class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        
        map<int, int>mp;
        
        for(int num : nums)
            mp[num] ++;
        long long count = 0;
        for(auto it: mp) {
            
            if(mp.count(k-it.first) && mp[k-it.first] > 0) 
                count += min(mp[it.first], mp[k-it.first]);
        }
        return count/2;
        
    }
};