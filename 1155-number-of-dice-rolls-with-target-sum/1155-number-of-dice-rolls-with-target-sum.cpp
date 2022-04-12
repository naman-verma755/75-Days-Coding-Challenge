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
        
        vector<vector<int>>dp(32, vector<int>(1002,-1));
       return findTotalWays(0, n, k, target, 0, dp);
        
    }
};