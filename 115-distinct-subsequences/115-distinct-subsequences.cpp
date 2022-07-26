class Solution {
public:
    
    int func(int i, int j, string s, string t, vector<vector<int>>&dp) {
        
        if(j == t.length())
            return 1;
        
        if(i == s.length())
            return 0;
        
        if(dp[i][j] != -1)
            return dp[i][j];
        if(s[i] == t[j]) {
            return dp[i][j] = func(i+1, j+1, s, t, dp)+func(i+1, j, s, t, dp);
        }
        else {
            return dp[i][j] = func(i+1, j, s, t, dp);
        }
    }
    int numDistinct(string s, string t) {
        // vector<vector<int>>dp(s.length(), vector<int>(t.length(), -1));
        // return func(0, 0, s, t, dp);
        int mod = 1000000007;
        int slen = s.length();
        int tlen = t.length();
        int dp[slen+1][tlen+1];
       
        for(int j = 0; j <= tlen; j++)
            dp[0][j] = 0;
         
        for(int i = 0; i <= slen; i++) 
            dp[i][0] = 1;
        for(int i = 1; i <= slen; i++) {
            for(int j = 1; j <= tlen; j++) {
                if(s[i-1] == t[j-1]) {
                    dp[i][j] = (dp[i-1][j-1]+dp[i-1][j])%mod;
                }
                else
                    dp[i][j] = dp[i-1][j];
            }
        }
        
        return dp[slen][tlen];
    }
};