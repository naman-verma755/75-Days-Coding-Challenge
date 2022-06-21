class Solution {
public:
    int func(int start, int end, string s, vector<vector<int>>&dp) {
        
        if(start == end)
            return 1;
        
        if(start > end)
            return 0;
        
        if(dp[start][end] != -1)
            return dp[start][end];
            
        if(s[start] == s[end])
            return dp[start][end] = func(start+1, end-1, s, dp) + 2;
        else {
            return dp[start][end] = max(func(start+1, end, s, dp), func(start, end-1, s, dp));
        }
        return 0;
    }
    int longestPalindromeSubseq(string s) {
        
        // vector<vector<int>>dp(s.length()+1, vector<int>(s.length()+1, -1))
        int len = s.length();
        int dp[len+1][len+1];
        
        for(int i = 0; i <= len; i++) 
            dp[0][i] = 0,dp[i][len] = 0 ;
        
        for(int i = 1; i <= len; i++) {
            for(int j = len-1; j >= 0; j--) {
                if(s[i-1] == s[j])
                    dp[i][j] = dp[i-1][j+1] + 1;
                else
                    dp[i][j] = max(dp[i-1][j], dp[i][j+1]);
            }
        }
        return dp[len][0];
        // return func(0, s.length()-1, s, dp);
    }
};