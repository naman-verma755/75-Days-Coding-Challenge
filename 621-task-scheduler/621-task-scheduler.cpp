class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        
        int maxFreq = 0;
        map<char, int>mp;
        for(char &ch : tasks) {
            mp[ch] ++;
            maxFreq = max(maxFreq, mp[ch]);
        }
        
        int ans = (maxFreq-1)*(n+1);
        for(auto it : mp) {
            if(it.second == maxFreq)
                ans++;
        }
        
       
        return max((int)tasks.size(), ans);
    }
};