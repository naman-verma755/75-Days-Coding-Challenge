class Solution {
public:
    
    int minPathSum(vector<vector<int>>& grid) {
        int rows = grid.size();
        int columns = grid[0].size();
        int dp[rows][columns];
        dp[0][0] = grid[0][0];
        for(int col = 1; col < columns; col ++)
            grid[0][col] = grid[0][col] + grid[0][col-1];
        for(int row = 1; row < rows; row++) 
            grid[row][0] = grid[row][0] + grid[row-1][0];
        
        for(int row = 1; row < rows; row++) {
            for(int col = 1; col < columns; col++) {
                grid[row][col] = grid[row][col] + min(grid[row-1][col],grid[row][col-1]);
            }
        }
        
        return grid[rows-1][columns-1];
   
    }
};