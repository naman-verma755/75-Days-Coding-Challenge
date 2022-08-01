class Solution {
public:
    int func(int i, int j, int m, int n, vector<vector<int>>&dp) {
        if(i == m && j == n)
            return 1;
        if(i > m || j > n)
            return 0;
        if(dp[i][j] != -1)
            return dp[i][j];
        
       return dp[i][j] = func(i+1, j, m, n, dp) + func(i, j+1, m, n, dp);
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m+1, vector<int>(n+1, -1));
        return func(1, 1, m, n, dp);
    }
};