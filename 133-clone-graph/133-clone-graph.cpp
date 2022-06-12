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
    Node* buildGraph(Node *nod, map<int, Node*>&st) {
        
        
        Node *node = new Node(nod->val); 
        st[nod->val] = node;
        
        for(auto it : nod->neighbors) {
            
            if(!st.count(it->val))
                node->neighbors.push_back( buildGraph(it, st));
            else {
                auto temp = st[it->val];
                node->neighbors.push_back(temp);
            }
                
        }
        return node;
        
    }
    Node* cloneGraph(Node* node) {
        if(node == NULL)
            return node;
        
        map<int, Node*>st;
        // set<int>st;
        
        return buildGraph(node, st);
        
        
        
    }
};