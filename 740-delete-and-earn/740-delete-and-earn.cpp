class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        
        map<int,int>mp;
        for(auto it : nums) {
            mp[it] ++;
        }
        vector<int>v;
        for(auto it : mp)
            v.push_back(it.first);
        int ans[v.size()];
        int maxi = 0;
        for(int i = 0; i < v.size(); i++)
        {
            ans[i] = (v[i]*mp[v[i]]);
            int a = 0;
            for(int j = i-1; j >= 0; j--)
            {
                if(abs(v[i]-v[j])>1)
                a = max(a, ans[j]);
            }
            ans[i] += a;
            maxi = max(maxi, ans[i]);
        }
        return maxi;
        // prev = -1;
        // int ans[i]
        // for(int i =0; i<v.size();i++)
        //     cout<<ans[i]<<" ";
        // if(v.size() < 2)
        //     return ans[0];
        // if(v.size() <= 2)
        //     return max(ans[0], ans[1]);
        // return max(ans[v.size()-1],max( ans[v.size()-2], ans[v.size()-3]));
    }
};