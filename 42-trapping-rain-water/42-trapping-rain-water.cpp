class Solution {
public:
    int trap(vector<int>& height) {
        int size = height.size();
        
        int leftMax = -1, rightMax = -1, left = 0, right = size-1;
        
        int totalTrapWater = 0;
        
        while(left <= right) {
            
            if(height[left] < height[right] ) {
                if(leftMax <= height[left]) 
                    leftMax = height[left];
                else
                    totalTrapWater += leftMax-height[left];
                left++;
            }
            else {
                if(rightMax <= height[right])
                    rightMax = height[right];
                else
                    totalTrapWater += rightMax-height[right];
                
                right--;
            }
        }
        return totalTrapWater;
        
    }
};