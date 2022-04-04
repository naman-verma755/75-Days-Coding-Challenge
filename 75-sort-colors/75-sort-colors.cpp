class Solution {
public:
    void sortColors(vector<int>& nums) {
        int zeroIndex = 0;
        int left = 0, right = nums.size()-1;
        while(left <= right) {
            if(nums[left] == 1)
                left++;
            else if(nums[left] == 0) {
                swap(nums[left], nums[zeroIndex]);
                left++;
                zeroIndex++;
            }
            else {
                swap(nums[left], nums[right]);
                // left++;
                right--;
            }
        }
        
    }
};