class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        
        int size = nums.size();
        for(int i = 0; i < size; i++)
        nums[i] *= nums[i];
        int right = size-1;
        int left = 0;
        vector<int>temp(size);
        int currInd = size-1;
        while(left <= right) {
            if(nums[left] < nums[right]){
                temp[currInd--] = nums[right];
                right--;
            }
            else {
                temp[currInd--] = nums[left];
                left++;
            }
            
            
        }
        return temp;
    }
};