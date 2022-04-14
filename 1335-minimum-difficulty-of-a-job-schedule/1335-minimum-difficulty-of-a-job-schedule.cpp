class Solution {
public:
//     int func(int in, int day, vector<int>& jobDifficulty, int d) {
        
//         int size = jobDifficulty.size();
//         if(in >= size)
//             return 20000;
//         if(day == d) {
//             int maxi = jobDifficulty[in];
//             for(int i = in+1; i < size; i++)
//                 maxi = max(maxi, jobDifficulty[i]);
            
//             // cout<<maxi<<" ";
//             return maxi;
//         }
        
//         int maxi = jobDifficulty[in];
//         int al = 20000;
//         for(int i = in+1; i < size; i++) {
//             int er = func(i, day+1, jobDifficulty, d)+maxi; 
//             al= min(al,er);
//             maxi = max(maxi,jobDifficulty[i]);
            
//         }
//         return al;
//     }
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        // vector<
        
        // if (n < D) return -1;
    int n= jobDifficulty.size();
        if(d > n)
            return -1;
    // let dp = new Array(n + 1).fill(Infinity);
        int dp[n+1];
        for(int i = 0; i < n; i++)
            dp[i] = 20000;
    dp[n] = 0;
        int D = d;
    
    for (int d = 1; d <= D; d++) {
        // cout<<"DAy="<<d<<" "<<endl;
        for (int  i = 0; i <= n - d; i++) {
           int maxd = 0; dp[i] =20000;

            for (int j = i; j <= n - d; j++) {
                maxd =  max(maxd, jobDifficulty[j]);
                dp[i] = min(dp[i], maxd + dp[j + 1]);
            }
            // for(int k = 0; k <= n; k++) {
            //     cout<<dp[k]<<" ";
            // }
            // cout<<endl;
        }
    }
    
    return dp[0];

        
    }
};