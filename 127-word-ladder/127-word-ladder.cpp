class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
        queue<string>q;
        q.push(beginWord);
        map<string, int>mp;
        for(int i = 0; i < wordList.size(); i++) {
            mp[wordList[i]] ++;
        }
        // if(mp.count(beginWord))
        //     mp.erase(beginWord);
        int steps = 0;
        while(!q.empty()) {
            int size = q.size();
            while(size > 0) {
                
                string top = q.front();
                if(top == endWord)
                            return steps+1;
                q.pop();
                
                for(int i = 0; i < top.length(); i++) {
                    char ch = top[i];
                    for(char c = 'a'; c <= 'z'; c++ ) {
                        if(c == ch)
                            continue;
                        top[i] = c;
                        
                        if(mp.count(top)) {
                            q.push(top);
                            mp.erase(top);
                        }
                    }
                    top[i] = ch;
                }
                size--;
            }
            steps++;
            
        }
    return 0;
        
    }
};