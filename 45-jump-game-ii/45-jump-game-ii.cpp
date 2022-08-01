class Solution {
public:
    int func(int index, vector<int>&nums, vector<int>&dp) {
        if(index >= nums.size()-1 )
            return 0;
        if(dp[index] != -1)
            return dp[index];
        int mini = INT_MAX, minSteps;
        for(int i = 1; i <= nums[index]; i++) {
            minSteps = func(index+i, nums, dp);
            mini = min(mini, minSteps);
        }
        return dp[index] = (mini == INT_MAX)?mini:mini+1;
        
    }
    int jump(vector<int>& nums) {
        vector<int>dp(nums.size()+3, -1);
        return func(0, nums, dp);
        
    }
};