struct Node{
    public:
 
    int val;
    int key;
    Node *left;
    Node *right;
    Node(int _key, int _val) {
        key = _key;
        val = _val;
    }
};

class LRUCache {
public:
    int capacity;
    int size;
    Node *head;
    Node *tail;
    map<int, Node*>mp;
    LRUCache(int _capacity) {
        size = 0;
        head = new Node(0, 0);
        tail = new Node(0, 0);
        capacity = _capacity;
        head->right = tail;
        tail->left = head;
        
    }
    void deleteNode(int _key) {
      
        Node *currNode = mp[_key];
        mp.erase(_key);
        Node *leftNode = currNode->left;
        Node *rightNode = currNode->right;
        currNode->left = NULL;
        currNode->right = NULL;
        leftNode->right = rightNode;
        rightNode->left = leftNode;
        
    }
    void insertNode(int key, int value) {
        
        Node *newNode = new Node(key, value);
        mp[key] = newNode;
        Node *temp = head->right;
        head->right = newNode;
        newNode->left = head;
        temp->left = newNode;
        newNode->right = temp;
    }
    
    int get(int key) {
        
        if(!mp.count(key))
            return -1;
        int val = mp[key]->val;
        deleteNode(key);
        insertNode(key, val);
        return val;
    }
    
    void put(int key, int value) {
        
        if(mp.count(key))
            deleteNode(key);
        else if(mp.size() == capacity)
            deleteNode(tail->left->key);
        insertNode(key, value);
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */