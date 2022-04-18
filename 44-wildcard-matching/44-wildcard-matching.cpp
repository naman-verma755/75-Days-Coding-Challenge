class Solution {
public:
    bool recur(int i, int j, string s, string p, int n, int m, vector<vector<int>>&dp) {
        // cout<<i<<" "<<j<<endl;
        
        if(i >= n && j >= m)
            return true;
        if(j >= m && i < n )
            return false;
        if(i >= n && j < m) {
            for(int ii = j; ii < m; ii++) {
                if(p[ii] != '*')
                    return false;
                
            }
            return true;
        }
            // return true;
        
        if(dp[i][j] != -1)
            return dp[i][j];
        if(s[i] == p[j] || p[j] == '?') {
            return dp[i][j] = recur(i+1, j+1, s, p, n, m, dp);
        }
         if(p[j] == '*') {
            return dp[i][j] =(recur(i+1, j, s, p, n, m, dp) || recur(i, j+1, s, p, n, m, dp));
        }
      
        return dp[i][j] = false;
    }
    bool isMatch(string s, string p) {
        int n = s.length();
        int m = p.length();
         vector<vector<bool>>dp(m+1, vector<bool>(n+1, false));
        
        dp[0][0] = true;
        bool fi = true;
        for(int i = 1; i <= m; i++) {
            
            // for(int j = 1; j <= i; j++)
            // {
                if(p[i-1] != '*') {
                    fi = false;
                    // break;
                }
          
            dp[i][0] = fi;
        }
        
        for(int i = 1; i <= m; i++) {
            for(int j = 1; j <= n; j++) {
                
        if(s[j-1] == p[i-1] || p[i-1] == '?') {
             dp[i][j] = dp[i-1][j-1];
        }
        else if(p[i-1] == '*') {
             dp[i][j] =dp[i-1][j] || dp[i][j-1];
        }
        else
        dp[i][j] = false;
                
            }
        }
        
        // for(int i = 0; i <= m; i++) {
        //     for(int j = 0; j <= n; j++) {
        //         cout<<dp[i][j]<<" ";
        //     }cout<<endl;
        // }
        return dp[m][n];
        
    }
// "a*ab"
// "baaabab"
};