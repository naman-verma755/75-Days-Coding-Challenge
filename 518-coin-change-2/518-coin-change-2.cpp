class Solution {
public:
    int change(int amount, vector<int>& coins) {
        
        int size = coins.size();
        int dp[size][amount+1];
        for(int i = 0; i < size; i++)
            dp[i][0] = 1;
        
        for(int i = 0; i < size; i++) {
            for(int j = 1; j <= amount; j++) {
                int ways = 0;
                if(i > 0)
                    ways += dp[i-1][j];
                if(j-coins[i] >= 0)
                    ways += dp[i][j-coins[i]];
                dp[i][j] = ways;
            }
        }
        return dp[size-1][amount];
        
    }
};