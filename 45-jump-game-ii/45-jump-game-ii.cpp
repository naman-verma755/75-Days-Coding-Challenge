class Solution {
public:
//     int func(int index, vector<int>&nums, vector<int>&dp) {
//         if(index >= nums.size()-1 )
//             return 0;
//         if(dp[index] != -1)
//             return dp[index];
//         int mini = INT_MAX, minSteps;
//         for(int i = 1; i <= nums[index]; i++) {
//             minSteps = func(index+i, nums, dp);
//             mini = min(mini, minSteps);
//         }
//         return dp[index] = (mini == INT_MAX)?mini:mini+1;
        
//     }
    int jump(vector<int>& nums) {
        
           int size = nums.size();
           int dp[size];
           for(int i = 1; i < size; i++)
               dp[i] = INT_MAX;
           dp[0] = 0;
        
           for(int i = 0; i < size; i++) {
               for(int j = 1; j <= nums[i]; j++) {
                   int index = i+j;
                   if(index >= size)
                       break;
                   if(dp[index] > dp[i]+1)
                       dp[index] = dp[i]+1;
               }
           }
        
        return dp[size-1];
        
        
    }
};