class Solution {
public:
    bool func(int i, int j, string p, string s, vector<vector<int>>&dp) {
        
        if(i == p.length() && j == s.length())
            return true;
        if(j < s.length() && i == p.length())
            return false;
        if(j == s.length()) {
            for(int it = i; it < p.length(); it++) {
                if(p[it] != '*')
                    return false;
            }
            return true;
        }
        if(dp[i][j] != -1)
            return dp[i][j];
        if(p[i] == s[j] || p[i] == '?') {
            return dp[i][j] = func(i+1, j+1, p, s, dp);
        }
        else if(p[i] == '*') 
            return dp[i][j] = (func(i, j+1, p, s, dp) || func(i+1, j, p, s, dp));
        else
            return dp[i][j] = false;
        
        
    }
    bool isMatch(string s, string p) {
        // vector<vector<int>>dp(p.length(), vector<int>(s.length(), -1));
        
        int dp[p.length()+1][s.length()+1];
        for(int i = 0; i <= s.length(); i++) 
            dp[0][i] = false;
        dp[0][0] = true;
        int i = 1;
        for( ; i <= p.length(); i++) {
            if(p[i-1] != '*')
                break;
            dp[i][0] = true;
        }
            
        for(; i<= p.length() ;i++) 
            dp[i][0] = false;
        
        for(int i = 1; i <= p.length(); i++) {
            for(int j = 1; j <= s.length(); j++) {
                if(p[i-1] == s[j-1] || p[i-1] == '?')
                    dp[i][j] = dp[i-1][j-1];
                else if(p[i-1] == '*')
                    dp[i][j] = dp[i][j-1] || dp[i-1][j];
                else
                    dp[i][j] = false;
            }
        }
        return dp[p.length()][s.length()];
        // return func(0, 0, p, s, dp);
    }
};