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
    int findMin(vector<int>&arr) {
        int size = arr.size();
        if(arr[0] <= arr[size-1])
            return 0;
        
        int start = 0, end = size-1, ans = 0;
        while(start <= end) {
            int mid = (start+end)/2;
            if(arr[mid] > arr[end]) {
                ans = mid;
                start = mid+1;
            }
            else
                end = mid-1;
        }
        return ans+1;
    }
    int search(vector<int>& nums, int target) {
        int size = nums.size();
        int k = findPivot(nums);
        // cout<<k<<" ";
        int start = 0, end = size-1, ans = 0;
        while(start <= end) {
            int mid = (start+end)/2;
            
            int l = (mid+k)%size;
            // cout<<l<<" ";
            if(nums[l] == target)
                return l;
            else if(nums[l] > target) {
                end = mid-1;
            }
            else
                start = mid+1;
        }
        return -1;
    }
};