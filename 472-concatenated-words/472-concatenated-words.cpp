class Solution {
public:
    bool func( string word, map<string, int>&mp) {
        // cout<<word<<" ";
        int n = word.length();
        if( n == 0)
            return true;
        
        string s = "";
        for(int j = 0; j < n; j++) {
            s+=word[j];
            if(mp.count(s) && func( word.substr(j+1, n), mp )) {
                return true;
            }
        }
        return false;
    }
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        map<string, int>mp, visited;
        
        for(int i = 0; i < words.size(); i++) {
            mp[words[i]] = 1;
        }
        vector<string>ans;
        for(int i = 0; i < words.size(); i++) {
            string s = "";
            // cout<<words[i]<<" ";
            if(words[i].length() == 1)
                continue;
            for(int j = 0; j < words[i].length(); j++) {
                
                s += words[i][j];
                
                if(mp.count(s) && j < words[i].length()-1) {
                    if(func( words[i].substr(j+1, words[i].length()), mp))
                        if(!visited[words[i]]) {
                            ans.push_back(words[i]);
                            visited[words[i]]++;
                        }
                        
                }
                
            }
            // cout<<endl;
        }
        return ans;
    }
};