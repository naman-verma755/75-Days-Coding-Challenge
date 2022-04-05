class Solution {
public:
    int maxArea(vector<int>& height) {
        
        int maxi = INT_MIN;
        int left = 0;
        int right = height.size()-1;
        while(left < right) {
            if(height[left] <= height[right]) {
                maxi = max(maxi,(right-left)*height[left]);
                left++;
            }
            else {
                maxi = max(maxi,(right-left)*height[right]);
                right--;
            }
            
        }
        return maxi;
        
    }
};