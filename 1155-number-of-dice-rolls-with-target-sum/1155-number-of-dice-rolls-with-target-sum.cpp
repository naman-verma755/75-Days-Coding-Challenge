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
        vector<vector<int>>dp(n+1, vector<int>(target+1, -1));
        return findWays(0, n, k, target, dp);
    }
};