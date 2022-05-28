class Solution {
public:
    int func(int i, int j, vector<vector<int>>&grid, vector<vector<int>>&dp) {
        
        int row = grid.size();
        int col = grid[0].size();
        if(i >= row || j >= col )
            return INT_MAX;
        // cout<<grid[i][j]<<" ";
        if(i == row-1 && j == col-1)
            return grid[i][j];
        if(dp[i][j] != -1)
            return dp[i][j];
        return dp[i][j] = min(func(i+1, j, grid, dp), func(i, j+1, grid, dp))+grid[i][j];
        
        
    }
    int minPathSum(vector<vector<int>>& grid) {
        vector<vector<int>>dp(grid.size()+1, vector<int>(grid[0].size()+1, -1));
        return func(0, 0, grid, dp);
    }
};