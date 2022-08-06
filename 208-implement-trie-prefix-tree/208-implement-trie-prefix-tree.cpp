class Trie {
public:
    struct trie {
        trie *a[26];
        bool flag = false;
    };
    trie *root;
    
    Trie() {
        root = new trie();
    }
    
    void insert(string word) {
        trie *temp = root;
        for(int i = 0; i < word.length(); i++) {
            if(temp->a[word[i]-'a'] == NULL)
                temp->a[word[i]-'a'] = new trie();
            temp = temp->a[word[i]-'a'];
        }
        temp->flag = true;
    }
    
    bool search(string word) {
        trie *temp = root;
        for(int i = 0; i < word.length(); i++) {
            if(temp->a[word[i]-'a'] == NULL)
                return false;
            temp = temp->a[word[i]-'a'];
        }
        if(temp->flag)
            return true;
        return false;
        
    }
    
    bool startsWith(string prefix) {
         trie *temp = root;
        for(int i = 0; i < prefix.length(); i++) {
            if(temp->a[prefix[i]-'a'] == NULL)
                return false;
            temp = temp->a[prefix[i]-'a'];
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