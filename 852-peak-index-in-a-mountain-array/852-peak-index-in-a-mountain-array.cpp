class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int size = arr.size();
       
        if(arr[0] > arr[1] )
            return 0;
        if(arr[size-2] < arr[size-1])
            return size-1;
        
        int start = 0, end = size-1, ans = -1;
        while(start <= end) {
            
            int mid = (start+end)/2;
            
            if(arr[mid] > arr[mid+1]) {
                ans = mid;
                end = mid-1;
            }
            else
                start = mid+1;
        }
          
            return ans;
        
        
    }
};