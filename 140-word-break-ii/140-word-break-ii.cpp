class Solution {
public:
    
    void find(string s, string prev, vector<string>& wordDict, map<string, int>&mp, vector<string>&ans) {
        
        
        if(s.length() == 0) {
            ans.push_back(prev);
        }
        
        string res = "";
        
        for(int i = 0; i < s.length(); i++) {
            
            res += s[i];
            
            if(mp.count(res)) {
                if(prev != "") {
                    find(s.substr(i+1, s.length()), prev+" "+res, wordDict, mp, ans);
                }
                else
                 find(s.substr(i+1, s.length()), res, wordDict, mp, ans);
                
                
            }
        }
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {

        vector<string>ans;
        map<string, int>mp;
        for(string &word : wordDict) 
            mp[word] = 1;
        find(s, "", wordDict, mp, ans);
        
        return ans;
    }
};