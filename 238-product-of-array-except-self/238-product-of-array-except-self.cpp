class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        
        int size = nums.size();
        vector<int>ans(size);
        int prefix[size];
        int suffix[size];
        prefix[0] = nums[0];
        suffix[size-1] = nums[size-1];
        
        
        for(int i = 1; i < size; i++) 
            prefix[i] = nums[i]*prefix[i-1];
        for(int j = size-2; j >= 0; j--) 
            suffix[j] = nums[j]*suffix[j+1];
        // for(auto it : prefix)
        //     cout<<it<<" ";
        ans[0] = suffix[1];
        ans[size-1] = prefix[size-2];
        for(int i = 1; i < size-1; i++)
            ans[i] = prefix[i-1]*suffix[i+1];
        
        
        return ans;
    }
};