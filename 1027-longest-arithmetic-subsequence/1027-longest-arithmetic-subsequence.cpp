class Solution {
public:
    int longestArithSeqLength(vector<int>& A) {
        
//         int size = nums.size();
//         vector<unordered_map<int, int>>v(size);
//         int maxi = 1;
//         for(int i = 1; i < size; i++) {
//             for(int j = 0; j < i; j++) {
                
//                 int diff = nums[i]-nums[j];
//                 if(v[j].count(diff)) {
//                         v[i][diff] = v[j][diff]+1;
//                     // else
//                     //     v[i][diff] = v[j][diff]+1;
//                 }
//                 else
//                     v[i][diff] = 2;
//                 maxi = max(v[i][diff],maxi);
                
//             }
//         }
//         return maxi;
        int n = A.size();
        int result = 0;
        vector<unordered_map<int, int>> dp(n);
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                int diff = A[i]-A[j];
                dp[i][diff] = dp[j].count(diff) > 0 ? dp[j][diff] + 1 : 2;
                result = max(result, dp[i][diff]);
            }
        }
        return result;
    }
};