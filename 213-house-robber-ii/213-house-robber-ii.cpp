class Solution {
public:
    int rob(vector<int>& nums) {
        
        int size = nums.size();
        if(size == 1)
            return nums[size-1];
        if(size == 2)
            return max(nums[size-1], nums[size-2]);
        
        if(size == 3)
            return max(nums[0], max(nums[1], nums[2]));
            
        int dp1[size];
        
        for(int i = 0; i < size-1; i++) {
            
            dp1[i] = nums[i];
            if(i-3 >= 0)
                dp1[i] += max(dp1[i-2], dp1[i-3]);
            else if(i-2 >= 0)
                dp1[i] += dp1[i-2];
        }
        
        int dp2[size+1];
        
        for(int i = size-1; i > 0; i--) {
            dp2[i] = nums[i];
            
            if(i+3 < size)
                dp2[i] += max(dp2[i+3], dp2[i+2]);
            else if(i+2 < size)
                dp2[i] += dp2[i+2];
        }
        
        int Money1 = max(dp1[size-2], dp1[size-3]);  // money amount gathered (exluding the last house)
        int Money2 = max(dp2[1], dp2[2]);
        
        return max(Money1, Money2);
    }
};