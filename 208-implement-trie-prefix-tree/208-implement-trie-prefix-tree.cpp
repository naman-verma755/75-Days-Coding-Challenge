
struct trie {
    trie *a[26];
    
    bool flag = false;
    
};

class Trie {
public:
    trie *root;
    Trie() {
         root = new trie();
    }
    
    void insert(string word) {
         
       trie* node = root;
        for(int i = 0; i < word.length(); i++) {
            
            if(node->a[word[i]-'a'] == NULL) {
                node->a[word[i]-'a'] = new trie();
            }
            node = node->a[word[i]-'a'];
        }
        node->flag = true;
        
    }
    
    bool search(string word) {
         trie *node = root;
        for(int i = 0; i < word.length(); i++) {
            
            if(node->a[word[i]-'a'] == NULL) {
                return false;
            }
            node = node->a[word[i]-'a'];
        }
        if(node->flag)
            return true;
        return false;
    }
    
    bool startsWith(string prefix) {
         trie *node = root;
        for(int i = 0; i < prefix.length(); i++) {
            
            if(node->a[prefix[i]-'a'] == NULL) {
                return false;
            }
            node = node->a[prefix[i]-'a'];
        }
        
            return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */