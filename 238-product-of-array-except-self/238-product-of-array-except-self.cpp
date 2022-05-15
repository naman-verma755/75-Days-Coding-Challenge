class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        
        int size = nums.size();
        vector<int>ans(size, 1);
//         int prefix[size];
//         int suffix[size];
//         prefix[0] = nums[0];
//         suffix[size-1] = nums[size-1];
        
        
//         for(int i = 1; i < size; i++) 
//             prefix[i] = nums[i]*prefix[i-1];
//         for(int j = size-2; j >= 0; j--) 
//             suffix[j] = nums[j]*suffix[j+1];
        // for(auto it : prefix)
        //     cout<<it<<" ";
        // nums[0] = suffix[1];
        // nums[size-1] = prefix[size-2];
        // for(int i = 1; i < size-1; i++)
        //     nums[i] = prefix[i-1]*suffix[i+1];
       int prevBegin = 1;
        int prevEnd = 1;
        for(int i = 0; i < size; i++) {
            ans[i] *= prevBegin;
            prevBegin *= nums[i];
            ans[size-i-1] *= prevEnd;
            prevEnd *= nums[size-i-1];
        }
        
        
        return ans;
    }
};