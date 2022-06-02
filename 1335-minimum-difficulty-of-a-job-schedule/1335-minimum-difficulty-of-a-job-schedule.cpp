class Solution {
public:
    
//     int func(int i, int d, int D, int maxi, vector<int>&job, vector<vector<int>>&dp) {
       
        // int k1 = 0;
//         if(d <= D-1 && i == job.size())
//             return INT_MAX;
        
//         if(d == D-1) {
//             for(int j = i; j < job.size(); j++)
//                 maxi= max(job[j], maxi);
//             return maxi;
//         }
//         // if(dp[i][d] != -1)
//         //     return dp[i][d];
        
//         maxi = max(job[i], maxi);
//         int k1 = func(i+1, d+1, D, 0, job, dp);
//         if(k1 != INT_MAX)
//             k1 += maxi;
//         int k2 = func(i+1, d, D,  maxi, job, dp);
//         // cout<<k1<<" "<<k2<<endl;
        
//         return min(k1, k2);
//     }
    
    int minDifficulty(vector<int>& job, int d) {
        int size = job.size();
       if(size < d)
           return -1;
        int D = d;
        vector<int>dp(size+1, 0);
        for( d = 1; d <= D; d++) {
            for(int i = 0; i < size; i++) {
                int maxi = job[i], r = INT_MAX;
                for(int j = i; j <= size-d; j++) {
                    maxi = max(maxi, job[j]);
                    
                    r = min(r, maxi+dp[j+1]);
                    
                }
                
                if(d == 1)
                dp[i] = maxi;
                else
                dp[i] = r;
            }
        }
        // if(dp[0] == INT_MAX)
        //     return -1;
        return dp[0];
        
    }
};