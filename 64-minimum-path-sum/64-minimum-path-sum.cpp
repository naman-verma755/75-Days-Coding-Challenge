class Solution {
public:
    
    int minPathSum(vector<vector<int>>& grid) {
        int rows = grid.size();
        int columns = grid[0].size();
        int dp[rows][columns];
        dp[0][0] = grid[0][0];
        for(int col = 1; col < columns; col ++)
            dp[0][col] = grid[0][col] + dp[0][col-1];
        for(int row = 1; row < rows; row++) 
            dp[row][0] = grid[row][0] + dp[row-1][0];
        
        for(int row = 1; row < rows; row++) {
            for(int col = 1; col < columns; col++) {
                dp[row][col] = grid[row][col] + min(dp[row-1][col],dp[row][col-1]);
            }
        }
        
        return dp[rows-1][columns-1];
   
    }
};