class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        int curr = nums[0];
        int freq = 1;
        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] == curr)
                freq++;
            else
                freq--;
            if(freq == 0)
            {
                freq++;
                curr = nums[i];
            }
        }
        return curr;
        
    }
};