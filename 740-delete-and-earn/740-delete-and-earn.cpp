class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {

        
        map<int, int>mp;
        for(int &num : nums) 
            mp[num]++;
        vector<int>v;
        for(auto it : mp)
            v.push_back(it.first);
        vector<int>dp(v.size()+1);
        int ans = 0;
        for(int i = 0; i < v.size(); i++) {
            int maxPoints = v[i] * mp[v[i]];
            
            int maxi = 0;
            for(int j = 0; j < i; j++) {
                if(v[i]-v[j] > 1)
                    maxi= max(maxi, dp[j]);
            }
            dp[i] = maxPoints + maxi;
            ans = max(ans, dp[i]);
        }
        
        return ans;
    }
};