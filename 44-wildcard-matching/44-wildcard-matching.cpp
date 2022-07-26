class Solution {
public:
   
//     bool func(int i, int j, string s, string p, vector<vector<int>>&dp) {
        
//         if(i == s.length() && j == p.length())
//             return true;
//         if(j == p.length() && i < s.length())
//             return false;
//         if(i == s.length()) {
//             for(int it = j; it < p.length(); it++)
//             {
//                 if(p[it] != '*')
//                     return false;
//             }
//             return true;
//         }
//         if(dp[i][j] != -1)
//             return dp[i][j];
        
//         if(s[i] == p[j] || p[j] == '?') {
//             return dp[i][j] = func(i+1, j+1, s, p, dp);
//         }
//         else if(p[j] == '*') {
//             return dp[i][j] = func(i+1, j, s, p, dp) || func(i, j+1, s, p, dp);
//         }
//         else 
//             return dp[i][j] = false;
//     }
    bool isMatch(string s, string p) {
        // vector<vector<int>>dp(s.length(), vector<int>(p.length(), -?1));
        int slen = s.length(), plen = p.length();
        int dp[plen+1][slen+1];
        for(int i = 0; i <= slen; i++)
            dp[0][i] = false;
        for(int i = 1; i <=plen; i++)
        dp[i][0] = false;
        for(int i = 1; i <=plen; i++)
        {
            if(p[i-1] != '*')
                break;
            dp[i][0] = true;
        }
        dp[0][0] = true;
        
        for(int i = 1; i <= plen; i++) {
            for(int j= 1; j <= slen; j++) {
                if(p[i-1] == s[j-1] || p[i-1] == '?')
                    dp[i][j]  = dp[i-1][j-1];
                else if(p[i-1] == '*')
                    dp[i][j] = dp[i-1][j] || dp[i][j-1];
                else
                    dp[i][j] = false;
            }
        }
        return dp[plen][slen];
        // return func(0, 0, s, p, dp);
    }
};