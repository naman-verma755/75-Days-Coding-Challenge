class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        
        int n = nums.size();
        // int sum = 0;
        // map<int, int>mp;
        // for(int num : nums) {
        //     if(mp.count(num))
        //         return num;
        //     mp[num]++;
        // }
        // long long k = (n*(n+1))/2;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < n-1; i++)
            if(nums[i] == nums[i+1])
                return nums[i];
        
        // O(nlogn);
        
        return 0;
    }
};