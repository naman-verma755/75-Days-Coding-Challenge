class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int size = nums.size();
        int prefixSum[size];
        prefixSum[0] = nums[0];
        for(int i = 1; i < size; i++)
            prefixSum[i] = nums[i]+prefixSum[i-1];
        
        if((prefixSum[size-1]-prefixSum[0]) == 0)
            return 0;
        for(int i = 1; i < size; i++)
        {
            if(prefixSum[i-1] == (prefixSum[size-1]-prefixSum[i]))
                return i;
        }
        
        return -1;
        
    }
};