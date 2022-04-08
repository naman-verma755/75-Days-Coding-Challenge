class Solution {
public:
    int findPivot(vector<int>&nums) {
        int size = nums.size();
        int left = 0, right = size-1;
        int pivot = 0;
        while(left <= right) {
            int mid = (left+right)/2;
            
            if(nums[mid] < nums[0]) {
                pivot = mid;
                right = mid-1;
            }
            else
                left = mid+1;
        }
        return pivot;
    }
    int search(vector<int>& nums, int target) {
        
        int pivot = findPivot(nums);
        
        int size = nums.size();
        int start = 0, end = size-1;
        while(start <= end) {
            int mid = (start+end)/2;
            int r = (mid+pivot)%size;
            
            if(nums[r] == target)
                return r;
            else if(nums[r] < target)
                start = mid+1;
            else
                end = mid-1;
        }
        return -1;
        
    }
};