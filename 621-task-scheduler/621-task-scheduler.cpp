class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        if(n == 0)
            return tasks.size();
        map<char, int>mp;
        int maxi = 0;
        for(char ch: tasks) 
        {
            mp[ch] ++;
            maxi = max(maxi, mp[ch]);
        }
        
        int ans = ((maxi-1) * (n+1));
        
        for(auto it : mp)
            if(it.second == maxi)
                ans++;
        
        return max((int)tasks.size(), ans);
    }
};