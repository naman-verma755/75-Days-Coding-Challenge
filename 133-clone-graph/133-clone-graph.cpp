/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* dfs(Node* node, map<int, Node*>&mp) {
        
        
        Node* root = new Node(node->val);
        mp[root->val] = root;
        vector<Node*>neighbors = node->neighbors;
        for(int i = 0; i < neighbors.size(); i++) {
            Node *temp = neighbors[i];
            if(!mp.count(temp->val)) {
                root->neighbors.push_back(dfs(temp, mp));
            }
            else {
                root->neighbors.push_back(mp[temp->val]);
            }
        }
        
        return root;
    }
    Node* cloneGraph(Node* node) {
        if(node == NULL)
            return NULL;
        map<int, Node*>mp;
        
        return dfs(node, mp);
    }
};