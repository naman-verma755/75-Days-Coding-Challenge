class Solution {
public:
    int binarySearch(vector<int>v, int &size) {
        
        int left = 0, right = size-1, ans = -1;
        while(left <= right) {
            int mid = (left+right)/2;
            
            if(v[mid] < 0) {
                ans = mid;
                right = mid-1;
            }
            else
                left = mid+1;
        }
    
        if(ans == -1)
            return 0;
        return size-ans;
    }
    int countNegatives(vector<vector<int>>& grid) {
        
         int count = 0;
         int rowSize = grid.size();
         int colSize = grid[0].size();
         for(int i = 0; i < rowSize; i++) {
             
             count += binarySearch(grid[i], colSize);
           
         }
        return count;
    }
};