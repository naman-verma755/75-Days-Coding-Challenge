class Solution {
public:
//     int func(int index, int amount, vector<int>&coins, vector<vector<int>>&v) {
//         int size = coins.size();
//         if(amount == 0)
//             return 1;
//         if(amount < 0 || index == size)
//             return 0;
//         if(v[index][amount] != -1)
//             return v[index][amount];
        
//         return v[index][amount] = (func(index, amount-coins[index], coins, v)+func(index+1, amount, coins, v));
//     }
    int change(int amount, vector<int>& coins) {
        // vector<vector<int>>v(coins.size()+1, vector<int>(amount+1, -1));
        // return func(0, amount, coins, v);
        int size = coins.size();
        int dp[size+1][amount+1];
        
        
        
        for(int i = 0; i <= amount; i++)
            dp[0][i] = 0;
        for(int i = 0; i <= size; i++)
            dp[i][0] = 1;
        // dp[0][0] = 1;
        
        for(int i = 1; i <= size; i++) {
            for(int j = 1; j <= amount; j++) {
                
                int pick = 0, notPick = 0;
                
                if(j-coins[i-1] >= 0)
                    pick = dp[i][j-coins[i-1]];
                notPick = dp[i-1][j];
                
                dp[i][j] = pick+notPick;
            }
        }
        
        return dp[size][amount];
    }
};