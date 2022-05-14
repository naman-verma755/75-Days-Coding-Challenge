class Solution {
public:
    int longestPalindromeSubseq(string s) {
        
        int length = s.length();
        int dp[length+1][length+1];
        
        for(int i = 0; i <= length; i++) {
            dp[0][i] = 0;
            dp[i][length] = 0;
        }
        
        for(int i = 1; i <= length; i++) {
            for(int j = length-1; j >= 0; j--) {
                
                if(s[i-1] == s[j]) {
                    dp[i][j] = dp[i-1][j+1]+1;
                }
                else
                    dp[i][j] = max(dp[i-1][j], dp[i][j+1]);
            }
        }
       
        
        return dp[length][0];
        
    }
};