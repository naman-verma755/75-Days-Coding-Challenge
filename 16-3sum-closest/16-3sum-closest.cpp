class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        
        int maxi = INT_MAX;
        int sum = 0;
        int size = nums.size();
        sort(nums.begin(), nums.end());
        for(int i = 0; i < size-2; i++) {
            int left = i+1;
            int right = size-1;
            while(left < right) {
                int a = nums[i], b= nums[left], c = nums[right];
                int r = a+b+c;
                int k = abs(r-target);
                if(k < maxi) {
                    maxi = k;
                    sum = r;
                    
                }
                if(r > target ) {
                    right--;
                }
                else if(r < target)
                    left ++;
                else
                    return r;
            }
        }
        return sum;
        
    }
};