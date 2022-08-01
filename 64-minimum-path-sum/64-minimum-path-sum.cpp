class Solution {
public:
//     int func(int i, int j, int n, int m, vector<vector<int>>& grid, vector<vector<int>>&dp) {
       
//         if(i == n-1 && j == m-1)
//             return grid[i][j];
        
//         if(dp[i][j] != -1)
//             return dp[i][j];
//         int down = INT_MAX,right = INT_MAX;
        
//         if(i+1 < n)
//             down = func(i+1, j, n, m, grid, dp);
//         if(j+1 < m)
//             right = func(i, j+1, n, m, grid, dp);
//         return dp[i][j] = min(down, right)+grid[i][j];
//     }
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        
        vector<int>prev(m+1);
        for(int i = n-1; i >= 0; i--) {
            vector<int>curr(m+1);
            for(int j = m-1; j >= 0; j--) {
                int k = INT_MAX;
                curr[j] = 0;
                if(i+1 < n)
                    k = min(k, prev[j]);
                if(j+1 < m)
                    k = min(k, curr[j+1]);
                if(k != INT_MAX)
                    curr[j] = k;
                curr[j] += grid[i][j];
            }
            prev = curr;
        }
        return prev[0];
    }
};