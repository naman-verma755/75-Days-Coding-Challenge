class Solution {
public:
//     int func(int i, int j, int m, int n, vector<vector<int>>&dp) {
//         if(i == m && j == n)
//             return 1;
//         if(i > m || j > n)
//             return 0;
//         if(dp[i][j] != -1)
//             return dp[i][j];
        
//        return dp[i][j] = func(i+1, j, m, n, dp) + func(i, j+1, m, n, dp);
//     }
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m+1, vector<int>(n+1, 0));
        // return func(1, 1, m, n, dp);
        dp[m][n] = 1;
        for(int i = m; i >= 1; i--) {
            for(int j = n; j >= 1; j--) {
                if(i+1 <= m)
                    dp[i][j] += dp[i+1][j];
                if(j+1 <= n)
                    dp[i][j] += dp[i][j+1];
            }
        }
        return dp[1][1];
    }
};