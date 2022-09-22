class Solution {
public:
//     int func(int i, int j, string s, string t, vector<vector<int>>&dp) {
//         if( j == t.length())
//             return 1;
//         if(i == s.length() || j == t.length())
//             return 0;
        
//         if(dp[i][j] != -1)
//             return dp[i][j];
//         if(s[i] == t[j]) {
//             return dp[i][j] = func(i+1, j+1, s, t, dp) + func(i+1, j, s, t, dp);
//         }
//         else
//             return dp[i][j] = func(i+1, j, s, t, dp) ;
        
    
//     }
    int numDistinct(string s, string t) {
        
        // vector<vector<int>>dp(s.length(), vector<int>(t.length(), -1));
        // return func(0, 0, s, t, dp);
        int mod = 1000000007;
        int len1 = s.length();
        int len2 = t.length();
        int dp[len1+1][len2+1];
        for(int i = 0; i <= len2; i++) 
            dp[0][i] = 0;
        for(int i = 0; i <= len1; i++)
            dp[i][0] = 1;
        
        for(int i = 1; i <= len1; i++) {
            for(int j = 1; j <= len2; j++) {
                if(s[i-1] == t[j-1])
                    dp[i][j] = (dp[i-1][j-1]+dp[i-1][j])%mod;
                else
                    dp[i][j] = dp[i-1][j];
            }
        }
        return dp[len1][len2];
    }
};