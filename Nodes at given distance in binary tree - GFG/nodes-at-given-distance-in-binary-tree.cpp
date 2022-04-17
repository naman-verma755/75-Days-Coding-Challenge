// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    
    return temp;
}

// Function to Build Tree
Node* buildTree(string str)
{   
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
            return NULL;
    
    // Creating vector of strings from input 
    // string after spliting by space
    vector<string> ip;
    
    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);
        
    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));
        
    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);
        
    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {
            
        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();
            
        // Get the current node's value from the string
        string currVal = ip[i];
            
        // If the left child is not null
        if(currVal != "N") {
                
            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->left);
        }
            
        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];
            
        // If the right child is not null
        if(currVal != "N") {
                
            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }
    
    return root;
}


 // } Driver Code Ends
/* A binary Tree node
struct Node
{
    int data;
    struct Node *left, *right;
};
*/

class Solution
{
private:

public:

    void traverse(Node *root, int target, Node **src, Node *prev, map<Node*, Node*>&mp) {
        if(root == NULL)
        return;
        
        if(prev != NULL)
        mp[root] = prev;
        if(root->data == target)
        *src = root;
        
        traverse(root->left, target, src, root, mp);
        traverse(root->right, target, src, root, mp);
        
        
    }
    vector <int> KDistanceNodes(Node* root, int target , int k)
    {
        // return the sorted vector of all nodes at k dist
        map<Node*, Node*>mp;
        map<Node*, int>visited;
        Node *src = NULL;
        
        traverse(root, target, &src, NULL, mp);
        // cout<<src->data<<endl;
        vector<int>ans;
        queue<pair<Node*, int>>q;
        q.push({src, 0});
        while(!q.empty()) {
            int size = q.size();
            while(size > 0) {
                
                auto it = q.front();
                q.pop();
                Node *node = it.first;
                int dist = it.second;
                
                // if(visited.count(node)) {
                //     size--;
                //     continue;
                // }
                
                visited[node] = 1;
                if(dist == k) {
                    
                    ans.push_back(node->data);
                    size--;
                    continue;
                }
                if(node->left != NULL && !visited.count(node->left)) {
                    q.push({node->left, dist+1});
                }
                if(node->right != NULL && !visited.count(node->right)) {
                    q.push({node->right, dist+1});
                }
                if(mp.count(node) && !visited.count(mp[node])) {
                    q.push({mp[node], dist+1});
                }
                size--;
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
        
        
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    getchar();
    
    Solution x = Solution();
    
    while(t--)
    {
        string s;
        getline(cin,s);
        Node* head = buildTree(s);
        
        int target, k;
        cin>> target >> k;
        getchar();
        
        vector <int> res = x.KDistanceNodes(head, target, k);
        
        for( int i=0; i<res.size(); i++ )
            cout<< res[i] << " ";
        cout<<endl;
    }
    return 0;
}
  // } Driver Code Ends