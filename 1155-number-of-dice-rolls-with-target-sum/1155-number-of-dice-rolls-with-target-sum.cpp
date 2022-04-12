class Solution {
public:
    int findTotalWays(int dice, int n, int k, int target, int sum, vector<vector<int>>&dp) {
        if(dice == n && sum == target)
            return 1;
        if(dice >= n || sum > target)
            return 0;
        int mod = 1000000007;
        if(dp[dice][sum] != -1)
            return dp[dice][sum];
        int ways = 0;
        for(int i = 1; i <= k; i++)
        {
            ways = ((ways % mod)+findTotalWays(dice+1, n, k, target, (sum + i), dp)%mod)%mod;
        }
        return dp[dice][sum] = ways;
    }
    int numRollsToTarget(int n, int k, int target) {
        int mod = 1000000007;
       int dp[n+1][target+1];
        memset(dp, 0, sizeof(dp));
        dp[0][0] = 1;
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= target; j++) {
                
                for(int e = 1; e <= k; e++) {
                    if(e <= j)
                    dp[i][j] = (dp[i][j]%mod+dp[i-1][j-e]%mod)%mod;
                    else
                        break;
                    
                }
            }
        }
        return dp[n][target];
       // return findTotalWays(0, n, k, target, 0, dp);
        
    }
};