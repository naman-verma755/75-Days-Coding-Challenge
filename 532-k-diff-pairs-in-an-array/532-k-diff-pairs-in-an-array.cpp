class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        
        map<int, int>mp;
        set<pair<int,int>>st;
        sort(nums.begin(), nums.end(), greater<int>());
        for(int i = 0; i < nums.size(); i++) {
            
            int val = nums[i] + k;
            if(mp.count(val)) {
                st.insert({min(val, nums[i]), max(val, nums[i])});
            }
            
            mp[nums[i]] ++;
            
        }
        // for(auto it = st.begin(); it != st.end(); it++)
        //     cout<<it->first<<" "<<it->second<<endl;
        return st.size();
        
    }
};