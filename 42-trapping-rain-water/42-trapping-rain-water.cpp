class Solution {
public:
    int trap(vector<int>& height) {
        int size = height.size();
        int leftMax[size];
        int rightMax[size];
        int maxi = INT_MIN;
        for(int i = 0; i < size; i++) {
            maxi = max(maxi, height[i]);
            leftMax[i] = maxi;
        }
        maxi = INT_MIN;
        for(int i = size-1; i >= 0; i--) {
            maxi = max(maxi, height[i]);
            rightMax[i] = maxi;
        }
        int totalTrapWater = 0;
        
        for(int i = 0; i < size; i++) {
            totalTrapWater += min(leftMax[i], rightMax[i])-height[i];
        }
        return totalTrapWater;
        
    }
};