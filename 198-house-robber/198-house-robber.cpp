class Solution {
public:
    
//     int func(int index, vector<int>&nums) {
//         if(index >= nums.size())
//             return 0;
        
//         int money1 = func(index+2, nums);
//         int money2 = func(index+3, nums);
        
//         return max(money1, money2) + nums[index];
//     }
    int rob(vector<int>& nums) {
        
        int size = nums.size();
        int dp[size];
        if(size == 2)
            return max(nums[0], nums[1]);
        if(size == 1)
            return nums[0];

        
        dp[0] = nums[0];
        dp[1] = nums[1];
        dp[2] = nums[2]+nums[0];
        // if(size <= 2)
            
        for(int i = 3; i < size; i++) {
            
            dp[i] = nums[i] + max(dp[i-2], dp[i-3]);
        }
        
        return max(dp[size-1], dp[size-2]);
    }
};