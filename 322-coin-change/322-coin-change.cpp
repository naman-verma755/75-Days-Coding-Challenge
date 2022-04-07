class Solution {
public:

    int coinChange(vector<int>& coins, int amount) {
        if(amount == 0)
            return 0;
        int size = coins.size();
      int dp[size][amount+1];
        
        // dp[coins.size()][amount+1];
        for(int i = 0; i < size; i++) {
            for(int j = 1; j <= amount; j++) {
                int count1 = INT_MAX, count2 = INT_MAX;
                if(i > 0)
                    count1 = dp[i-1][j];
                if(j-coins[i] == 0)
                    count2 = 1;
                if(j-coins[i] > 0 && dp[i][j-coins[i]] != INT_MAX) {
                  
                        count2 = 1+dp[i][j-coins[i]];
                }
                    
                dp[i][j] = min(count1, count2);
            }
        }
        
        
      
        if(dp[size-1][amount] == INT_MAX)
            return -1;
        return dp[size-1][amount] ;
        
    }
};