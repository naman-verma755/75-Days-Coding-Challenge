class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        
        // int n = nums.size();
        // int sum = 0;
        map<int, int>mp;
        for(int num : nums) {
            if(mp.count(num))
                return num;
            mp[num]++;
        }
        // long long k = (n*(n+1))/2;
        
        return 0;
    }
};