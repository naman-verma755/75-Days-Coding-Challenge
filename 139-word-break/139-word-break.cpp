class Solution {
public:
    
    
    bool func( string s, map<string, int>&mp, map<string, bool>&dp ) {
        
        // cout<<index<<" ";
        if(s.length() == 0)
            return true;
        if(dp.count(s))
            return dp[s] ;
        string res = "";
        for(int i = 0; i < s.length(); i++) {
            res += s[i];
            // cout<<res<<" ";
            if(mp.count(res) && func( s.substr(i+1, s.length()), mp, dp))
            return dp[res] =  true;
        }
        return dp[s] = false;
            
            
        
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        
        map<string, int>mp;
        map<string, bool>dp;
        for(int i = 0; i < wordDict.size(); i++) {
            mp[wordDict[i]]++;
        }
        // for(auto it : mp)
        //     cout<<it.first<<" ";
        
        return func( s, mp, dp);
        
    }
};