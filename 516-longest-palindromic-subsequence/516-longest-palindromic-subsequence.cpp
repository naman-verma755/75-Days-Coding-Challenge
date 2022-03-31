class Solution {
public:
    int longestPalindromeSubseq(string s) {
        
        int n = s.length();
        int dp[n][n];
        for(int i = 0; i < n; i++)
            dp[i][i] = 1;
        for(int l = 1; l < n; l++) {
            for(int j = 0, k = j+l; k < n; k++, j++) {
                // cout<<j<<k<<" ";
                if(s[j] == s[k])
                {
                    if(l == 1)
                        dp[j][k] = 2;
                    else
                        dp[j][k] = 2+dp[j+1][k-1];
                }
                else
                    dp[j][k] = max(dp[j][k-1], dp[j+1][k]);
            }
        }
  
        return dp[0][n-1];
        
    }
};