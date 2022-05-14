class Solution {
public:
    int func(int i, int sum, int amount, vector<int>&a) {
        
        if(i >= a.size() || sum > amount)
            return 0;
        
        if(sum == amount)
            return 1;
        
        return func(i, sum+a[i], amount, a)+func(i+1, sum, amount, a);
            
        
    }
    int change(int amount, vector<int>& coins) {
        
        // return func(0, 0, amount, coins);
        int size = coins.size();
        int dp[size+1][amount+1];
        
        for(int i = 0; i <= size; i++) {
         
            dp[i][0] = 1;
        }
        for(int i = 0; i <= amount; i++) {
            dp[0][i] = 0;
            // dp[i][0] = 1;
        }
        dp[0][0] = 1;
        
        for(int i = 1; i <= size; i++) {
            for(int j = 1; j <= amount; j++) {
                int sum = 0;
                if(j-coins[i-1] >= 0)
                    sum += dp[i][j-coins[i-1]];
                sum += dp[i-1][j];
                dp[i][j] = sum;
            }
        }
        
        return dp[size][amount];
        
    }
};