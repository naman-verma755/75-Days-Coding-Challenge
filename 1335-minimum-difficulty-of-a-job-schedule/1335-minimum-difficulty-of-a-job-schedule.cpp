class Solution {
public:
//     int func(int index, int maxi, vector<int>&jobDifficulty, int d, int days, vector<vector<int>>&dp) {
//         int size = jobDifficulty.size();
//         if(index >= size && d < days)
//             return INT_MAX;
        
//         if(d == days) {
//             for(int i = index; i < size; i++)
//                 maxi = max(maxi, jobDifficulty[i]);
                
//             return maxi;
//         }
//         if(dp[index][d] != -1)
//             return dp[index][d];
//         int k1 = func(index+1, max(maxi, jobDifficulty[index]), jobDifficulty, d, days, dp);
//         int k2 = func(index+1, jobDifficulty[index], jobDifficulty, d+1, days, dp);
//             if(k2 != INT_MAX)
//                 k2 += maxi;
//         return dp[index][d] = min(k1, k2);
//     }
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        // vector<vector<int>>dp(jobDifficulty.size()+1, vector<int>(d+1, -1));
        // int r =  func(0, 0, jobDifficulty, 0, d, dp);
        // if(r == INT_MAX)
        //     return -1;
        // return r;
        int size = jobDifficulty.size();
        if(size < d)
            return -1;
        int dp[size];
        for(int day = 1; day <= d; day++) {
            for(int i = 0; i <= size-day; i++) {
                int maxi = INT_MIN, re = INT_MAX;
                for(int k = i; k <= size-day; k++) {
                    if(day == 1)
                        maxi = max(jobDifficulty[k], maxi);
                    else 
                    {
                        maxi = max(maxi, jobDifficulty[k]);
                        // cout<<(maxi)<<" ";
                        re = min(re, (maxi+dp[k+1]));
                    }
                }
                // cout<<endl;
                
                if(day == 1)
                    dp[i] = maxi;
                else
                    dp[i] = re;
                
            }
        }
        return dp[0];
    }
};