class Solution {
public:
    bool find(string s, map<string, int>&mp, map<string, bool>&dp) {
        
        if(s.length() == 0)
            return true;
        
        if(dp.count(s))
            return dp[s];
        // cout<<s<<" ";
        string res = "";
        
        for(int i = 0; i < s.length(); i++) {
            
            res += s[i];
            if(mp.count(res) && find(s.substr(i+1, s.length()), mp, dp))
               return dp[res] = true;
               
        }
        return dp[res] = false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        
        map<string, int>mp;
        map<string, bool>dp;
        for(string &word : wordDict)
            mp[word] = 1;
        
        if(find(s, mp, dp))
            return true;
        return false;
    }
};