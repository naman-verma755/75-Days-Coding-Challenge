class Solution {
public:
//     int func(int start, int end, string s,  vector<vector<int>>&dp) {
        
//         if(start == end)
//             return 1;
//         if(start > end)
//             return 0;
    
//         if(dp[start][end] != -1)
//             return dp[start][end];
//         if(s[start] == s[end]) {
//             return dp[start][end] = func(start+1, end-1, s, dp) + 2;
//         } else {
//             return dp[start][end] = max(func(start+1, end, s, dp), func(start, end-1, s, dp));
//         }
//         return 0;
//     }
    int longestPalindromeSubseq(string s) {
        // vector<vector<int>>dp(s.length()+1, vector<int>(s.length()+1, -1));
        
        int len = s.length();
        int dp[len][len];
        for(int i = 0; i < len; i++)
            dp[i][i] = 1;
        for(int k = 1; k < len; k++) {
            for(int i = 0, j = k; j < s.length(); i++,j++) {
                if(s[i] == s[j]) {
                    dp[i][j] = 2;
                    if((j-i) > 1)
                        dp[i][j] += dp[i+1][j-1];
                }
                else
                    dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
            }
        }
        return dp[0][len-1];
        
    }
};