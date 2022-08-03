class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
        int maxi = nums[0];
        int maxProduct = nums[0];
        int minProduct = nums[0];
        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] < 0)
                swap(maxProduct, minProduct);
            
            maxProduct = max(nums[i], nums[i]*maxProduct);
            minProduct = min(nums[i], nums[i]*minProduct);
            maxi = max(maxi, max(maxProduct, minProduct));
        }
        return maxi;
    }
};