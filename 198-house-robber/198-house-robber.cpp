class Solution {
public:
    int rob(vector<int>& nums) {
        int size = nums.size();
        if(size == 1)
            return nums[0];
        for(int i = 0; i < size; i++) {
            int k = -1;
            if(i-2 >= 0)
                k = nums[i-2] + nums[i];
            if(i-3 >= 0)
                k = max(k,(nums[i-3] + nums[i]));
            if(k != -1)
            nums[i] = k;
        }
        return max(nums[size-1], nums[size-2]);
        
    }
};