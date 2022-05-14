class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
        set<string>st;
        
        for(string word: wordList)
            st.insert(word);
        queue<string>q;
        q.push(beginWord);
        int count = 1;
        while(!q.empty()) {
            
            int size = q.size();
            
            while(size > 0) {
                
                string word = q.front();
                q.pop();
                
                for(int i = 0; i < word.length(); i++) {

                    char prev = word[i];
                    string re = word;
                    
                    for(char ch = 'a'; ch <= 'z'; ch++) {
                        word[i] = ch;
                        
                        
                        if(st.find(word) != st.end()) {
                            if(word == endWord){
                            // cout<<word<<" ";
                            // cout<<word<<" "<<endWord<<endl;
                            return count+1;
                        }
                        q.push(word);
                            st.erase(word);
                        }
                    }
                    word[i] = prev;
                }
                size--;
            }
            count++;
        }
        return 0;
        
    }
};