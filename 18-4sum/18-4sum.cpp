class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>>vec;
        int n = nums.size();
        for(int i=0; i<n-3; )
        {
            int q= nums[i];
            for(int j = i+1; j<n-2; ) 
            {
                int y = nums[j];
                int su = target-(nums[i] + nums[j]);
                int left = j+1, right = n-1;
                while(left < right) 
                {
                    int as = nums[left];
                    int ad = nums[right];
                    if((nums[left]+nums[right]) < su)
                    {
                        left++;
                    }
                    else if((nums[left]+nums[right]) > su)
                    {
                        right --;
                        
                    }
                    else 
                    {
                        vector<int>v;
                        v.push_back(nums[i]);
                        v.push_back(nums[j]);
                        v.push_back(nums[left]);
                        v.push_back(nums[right]);
                        vec.push_back(v);
                        
                        while(left<right && nums[left] == as)
                            left++;
                        
                        while(left < right && nums[right] == ad)
                            right--;
                        
                    }
                }
                
                while(j<n-2 && y == nums[j])
                    j++;
            }
            while( i< n-3 && q == nums[i])
                i++;
            
        }
        return vec;
    }
};