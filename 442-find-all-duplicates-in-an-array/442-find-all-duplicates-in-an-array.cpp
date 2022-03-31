class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        
        vector<int>ans;
        for(int i = 0; i < nums.size(); i++) {
            int k = nums[i];
            if(k < 0)
                k *= -1;
          
            if(nums[k-1] < 0) {
                ans.push_back(k);
            }
            else
            {
                nums[k-1] *= -1;
            }
         
        }
        return ans;
    }
};