class Solution {
public:
    int findWays(int index, int n, int k, int target, vector<vector<int>>&dp) {
        long long mod = 1000000007;
        if(target == 0 && index == n)
            return 1;
        
        if(index == n || target < 0)
            return 0;
        
        if(dp[index][target] != -1)
            return dp[index][target];
        
        long long sum = 0;
        for(int j = 1; j <= k; j++) {
            sum = (sum+findWays(index+1, n, k, target-j, dp))%mod;
        }
        return dp[index][target] = sum;
    }
    int numRollsToTarget(int n, int k, int target) {
        // vector<vector<int>>dp(n+1, vector<int>(target+1, 0));
         long long mod = 1000000007;
        int dp[n+1][target+1];
        
        for(int i = 0; i <= n; i++)
            dp[i][0] = 0;
        for(int j = 0; j <= target; j++)
            dp[0][j] = 0;
        dp[0][0] = 1;
        
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= target; j++) {
                long long sum = 0;
                for(int q = 1; q <= k; q++) {
                    if(j-q >= 0)
                    sum = (sum+dp[i-1][j-q])%mod;
                    else
                        break;
                }
                dp[i][j] = sum;
            }
        }
        
        return dp[n][target];
    }
};