struct node {
    
    int key;
    int val;
    node *next;
    node *prev;
    
    node(int _key, int _val) {
        key = _key;
        val = _val;
    }
};

class LRUCache {
public:
    node *head = new node(-1, -1);
    node *tail = new node(-1, -1);
    map<int, node*>mp;
    int size;
    
    LRUCache(int capacity) {
        size = capacity;
        
        head->next = tail;
        tail->prev = head;
        
    }
    
    void del(node *_node) {
        
        node *prevNode = _node->prev;
        node *nextNode = _node->next;
        prevNode->next = nextNode;
        nextNode->prev = prevNode;
        mp.erase(_node->key);
        delete _node;
    }
    
    int get(int key) {
        if(!mp.count(key))
            return -1;
        
        int value = mp[key]->val;
        
        node *temp = mp[key];
        del(temp);
        
        put(key, value);
        return value;
        
        
        
        
    }
    
    void put(int key, int value) {
        
        if(mp.count(key)) {
            del(mp[key]);
        }
        if(mp.size() == size)
        {
            del(tail->prev);
        }
        node *loc_node = new node(key, value);
        mp[key] = loc_node;
        
        node *temp = head->next;
        head->next = loc_node;
        loc_node->prev = head;
        loc_node->next = temp;
        temp->prev = loc_node;
        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */