class Solution {
public:
    
//     int func(int i, int j, vector<vector<int>>& dungeon, vector<vector<int>>&dp)
//     {
//         int row = dungeon.size();
//         int col = dungeon[0].size();
        
//         // if(i >= row || j >= col)
//         //     return;
        
        
//         if(i == row-1 && j == col-1){
//             if(dungeon[i][j] <= 0)
//             return dungeon[i][j];
//             else
//                 return 0;
//         }
//         if(dp[i][j] != -1)
//             return dp[i][j];
//         int r = INT_MIN;
        
//         if(i+1 < row )
//             r = max(r, func(i+1, j, dungeon, dp));
        
//         if(j+1 < col)
//             r = max(r, func(i, j+1, dungeon, dp));
//         r += dungeon[i][j];
//         if(r >= 0)
//             return dp[i][j] = 0;
//         return dp[i][j] = r;
//     }
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        
        // vector<vector<int>>dp(dungeon.size(), vector<int>(dungeon[0].size(), -1));
        // int ans = func(0, 0, dungeon, dp);
        // if(ans >= 0)
        //     return 1;
        // // cout<<ans<<" ";
        // return abs(ans)+1;
        
        int rows = dungeon.size();
        int columns = dungeon[0].size();
        
        int dp[rows+1][columns+1];
        dp[rows-1][columns-1] = (dungeon[rows-1][columns-1] > 0) ? 0 : dungeon[rows-1][columns-1];
        for(int i = rows-2; i >= 0; i--) {
            dp[i][columns-1] = dungeon[i][columns-1]+dp[i+1][columns-1];
            if(dp[i][columns-1] > 0)
                dp[i][columns-1] = 0;
            
        }
         for(int i = columns-2; i >= 0; i--) {
            dp[rows-1][i] = dungeon[rows-1][i]+dp[rows-1][i+1];
            if(dp[rows-1][i] > 0)
                dp[rows-1][i] = 0;
        }
        
        for(int i = rows-2; i >= 0; i--) {
            for(int j = columns-2; j >= 0; j--) {
                dp[i][j] = dungeon[i][j]+max(dp[i+1][j], dp[i][j+1]);
                if(dp[i][j] > 0)
                    dp[i][j] = 0;
            }
        }
        if(dp[0][0] >= 0)
            return 1;
        return abs(dp[0][0])+1;
    }
};