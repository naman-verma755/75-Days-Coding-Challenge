class Solution {
public:
    bool func(int i, int j, string s, string p, vector<vector<int>>&dp) {
        int n = s.length();
        int m = p.length();
        
        if(i >= n && j >= m)
            return true;
        if(i < n && j >= m)
            return false;
        if(i >= n && j < m) {
            for(int k = j; k < m; k++) {
                if(p[k] != '*')
                    return false;
            }
            return true;
        }
        
        
        if(dp[i][j] != -1)
            return dp[i][j];
        if(s[i] == p[j] || p[j] == '?')  {
            return dp[i][j] = func(i+1, j+1, s, p, dp);
        }
        if(p[j] == '*') {
            return dp[i][j] = func(i+1, j, s, p, dp) || func(i, j+1, s, p, dp);
        }
    
            return dp[i][j] = false;
    }
    bool isMatch(string s, string p) {
        int n = s.length();
        int m = p.length();
        vector<vector<bool>>dp(m+1, vector<bool>(n+1,false));
        for(int i = 1; i <= m; i++) {
            
            if(p[i-1] != '*')
                break;
            dp[i][0] = true;
            
        }
        dp[0][0] = true;
        for(int i = 1; i <= m; i++) {
            for(int j = 1; j <=n; j++) {
                if(s[j-1] == p[i-1] || p[i-1] == '?'){
                    dp[i][j] = dp[i-1][j-1];
                }
                else if(p[i-1] == '*') {
                    dp[i][j] = dp[i-1][j] || dp[i][j-1];
                }
                else
                    dp[i][j] = false;
            }
        }
        
        return dp[m][n];
        
        
    }
};