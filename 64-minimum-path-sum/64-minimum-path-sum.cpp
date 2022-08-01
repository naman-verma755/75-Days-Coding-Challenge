class Solution {
public:
    int func(int i, int j, int n, int m, vector<vector<int>>& grid, vector<vector<int>>&dp) {
       
        if(i == n-1 && j == m-1)
            return grid[i][j];
        
        if(dp[i][j] != -1)
            return dp[i][j];
        int down = INT_MAX,right = INT_MAX;
        
        if(i+1 < n)
            down = func(i+1, j, n, m, grid, dp);
        if(j+1 < m)
            right = func(i, j+1, n, m, grid, dp);
        return dp[i][j] = min(down, right)+grid[i][j];
    }
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>>dp(n+1, vector<int>(m+1));
        // dp[n-1][m-1] = grid[n-1][m-1];
        // return func(0, 0, n, m, grid, dp);
        for(int i = n-1; i >= 0; i--) {
            for(int j = m-1; j >= 0; j--) {
                int k = INT_MAX;
                dp[i][j] = 0;
                if(i+1 < n)
                    k = min(k, dp[i+1][j]);
                if(j+1 < m)
                    k = min(k, dp[i][j+1]);
                if(k != INT_MAX)
                    dp[i][j] = k;
                dp[i][j] += grid[i][j];
            }
        }
        return dp[0][0];
    }
};