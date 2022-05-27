class Solution {
public:
//     int findCombinations(int index, int amount, vector<int>&coins, vector<vector<int>>dp) {
        
//         if(amount > 0 && index >= coins.size() )
//             return 0;
//         if(amount == 0 )
//             return 1;
        
//         if(dp[index][amount] != -1)
//             return dp[index][amount];
//         int takeIt = 0;
//         if(amount-coins[index] >= 0)
//         takeIt = findCombinations(index, amount-coins[index], coins, dp);
        
//         int notTakeIt = findCombinations(index+1, amount, coins, dp);
        
//         return dp[index][amount] = takeIt+notTakeIt;
//     }
    int change(int amount, vector<int>& coins) {
        // vector<vector<int>>dp(coins.size()+1, vector<int>(amount+1, -1));
        // return findCombinations(0, amount, coins, dp);
        
        int dp[coins.size()+1][amount+1];
        
        for(int i = 0; i <= amount; i++)
            dp[0][i] = 0;
        for(int i = 0; i <= coins.size(); i++)
            dp[i][0] = 1;
        dp[0][0] = 1;
        
        for(int i = 1; i <= coins.size(); i++) {
            for(int j = 1; j <= amount; j++) {
                int takeIt = 0, notTakeIt = 0;
                if(j-coins[i-1] >= 0) 
                    takeIt += dp[i][j-coins[i-1]];
                notTakeIt+= dp[i-1][j];
                dp[i][j] = takeIt+notTakeIt;
            }
        }
        
        return dp[coins.size()][amount];
        
    }
};