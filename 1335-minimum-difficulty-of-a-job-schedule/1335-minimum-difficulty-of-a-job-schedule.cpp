class Solution {
public:
//     int func(int i, int j, vector<int>&a, int d, int maxi, vector<vector<vector<int>>>&dp) {
        
//         int size = a.size();
//         if(j == d) {
//             while(i < size) {
//                 maxi = max(maxi, a[i]);
//                 i++;
//             }
//             return maxi;
//         }
//         if( i == size)
//             return 10005;
        
//         if(dp[i][j][maxi] != -1)
//             return dp[i][j][maxi];
        
//         maxi = max(maxi, a[i]);
//         int k1 = func(i+1, j, a, d, maxi, dp);
//         int k2 = func(i+1, j+1, a, d, 0, dp)+maxi;
//         return dp[i][j][maxi] = min(k1, k2);
//     }
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int size= jobDifficulty.size();
        if(d > size)
            return -1;
        
        // vector<vector<vector<int>>>dp(size+1, vector<vector<int>>(d+1, vector<int>(1005, -1)));
        // return func(0, 0, jobDifficulty, d, 0, dp);
         vector<int>dp(size, 0);
        
        for(int i = 0; i < d; i++) {
            for(int j = 0; j < size-i; j++) {
                 int maxi = 0, maxAmount = INT_MAX;
                for(int k = j; k <size-i; k++) {
                    if(i == 0)
                        maxi = max(jobDifficulty[k], maxi);
                    else {
                        maxi = max(maxi, jobDifficulty[k]);
                        maxAmount = min(maxAmount, maxi+dp[k+1]);
                    }
                }
                if(i == 0)
                    dp[j] = maxi;
                else
                    dp[j] = maxAmount;
            }
            // for(auto it : dp)
            //     cout<<it<<" ";
            // cout<<endl;
        }
        
        return dp[0];
    }
};