class Solution {
public:
    int rob(vector<int>& nums) {
        
        int size = nums.size();
        if(size == 1)
            return nums[0];
        if(size == 2)
            return max(nums[0], nums[1]);
        int maxAmount1[size];
        int maxAmount2[size];
        maxAmount1[0] = nums[0];
        maxAmount1[1] = nums[1];
        for(int i = 0; i < size-1; i++) {
            int k = -1;
            if(i-2 >= 0) 
                k = nums[i] + maxAmount1[i-2];
            if(i-3 >= 0)
                k = max(k,(nums[i] + maxAmount1[i-3]));
            if(k != -1)
                maxAmount1[i] = k;
            else
                maxAmount1[i] = nums[i];
            
        }
        int ans1 = max(maxAmount1[size-2], maxAmount1[size-3]);
        maxAmount1[size-1] = nums[size-1];
        maxAmount1[size-2] = nums[size-2];
        for(int i = size-1; i > 0; i--) {
            int k = -1;
            if(i+2 < size) 
                k = nums[i] + maxAmount2[i+2];
            if(i+3 < size)
                k = max(k,(nums[i] + maxAmount2[i+3]));
            if(k != -1)
                maxAmount2[i] = k;
            else
                maxAmount2[i] = nums[i];
            
        }
        int ans2 = max(maxAmount2[1], maxAmount2[2]);
//         for(int i =0 ; i< size-1; i++)
//          cout<<maxAmount1[i]<<" ";
//         cout<<endl;
//          for(int i =1 ; i< size; i++)
//          cout<<maxAmount2[i]<<" ";
        
        
        return max(ans1, ans2);
        
    }
};