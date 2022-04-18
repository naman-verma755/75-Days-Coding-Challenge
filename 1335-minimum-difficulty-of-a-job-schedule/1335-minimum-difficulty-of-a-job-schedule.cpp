class Solution {
public:
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        
        int n = jobDifficulty.size();
        if(d > n)
            return -1;
        vector<int>dp(n+1, 20000);
        
        for(int j = 1; j <= d; j++) {
            for(int i = 0; i <= n-j; i++) {
                
                int maxi = INT_MIN, re = INT_MAX;
                for(int k = i; k <= n-j; k++) {
                    if(j == 1) {
                        maxi = max(jobDifficulty[k], maxi);
                    }
                    else {
                        maxi = max(maxi, (jobDifficulty[k] ));
                        re = min(re, maxi+dp[k+1]);
                    }
                }
                if(j == 1)
                dp[i] = maxi;
                else
                    dp[i] = re;
            }
            // for(int i = 0; i < n ;i++)
            //     cout<<dp[i]<<" ";
            // cout<<endl;
        }
        return dp[0];
    }
};