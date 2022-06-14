struct Node{
    int key;
    int value;
    Node *left;
    Node *right;
    
    Node(int key_, int value_) {
        key = key_;
        value = value_;
        left = right = NULL;
    }
};

class LRUCache {
public:
    
    int size = 0;
    map<int, Node*>mp;
    Node *head = new Node(-1, -1);
    Node *tail = new Node(-1,-1);
    LRUCache(int capacity) {
        size = capacity;
        head->right = tail;
        tail->left = head;
    }
    
    void insert(int key, int value) {
        
        // head->right = tail;
        Node *newNode = new Node(key, value);
        mp[key] = newNode;
        Node *temp = head->right;
        head->right = newNode;
        newNode->left = head;
        newNode->right = temp;
        temp->left = newNode;
    }
    void deleteKey(int key) {
        
        Node* currNode = mp[key];
        mp.erase(key);
        Node*leftNode = currNode->left;
        Node*rightNode = currNode->right;
        currNode->left = currNode->right = NULL;
        delete(currNode);
        leftNode->right = rightNode;
        rightNode->left = leftNode;
        
        
    }
    int get(int key) {
        
        if(!mp.count(key))
            return -1;
        int value = mp[key]->value;
        deleteKey(key);
        
        insert(key, value);
        
        return value;
    }
    
    void put(int key, int value) {
        
         if(mp.count(key)) {
            deleteKey(key);
        }
        
        if(mp.size()+1 > size) {
            deleteKey(tail->left->key);
        }
       
        insert(key, value);
        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */