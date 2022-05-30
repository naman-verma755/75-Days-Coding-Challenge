class Solution {
public:
    int findMin(vector<int>& nums) {
        int size = nums.size();
        if(nums[0] < nums[size-1])
            return nums[0];
        
        int start = 0, end = size,ans = -1;
        while(start <= end) {
            int mid = (start+end)/2;
            if(nums[mid] > nums[size-1]) {
                ans = mid;
                start = mid+1;
                
            }
            else
                end = mid-1;
        }
        return nums[ans+1];
    }
};