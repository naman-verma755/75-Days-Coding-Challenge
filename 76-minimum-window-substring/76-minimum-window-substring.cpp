class Solution {
public:
    string minWindow(string s, string t) {
        
        map<char, int>mp1, mp2;
        for(char ch : t)
            mp1[ch]++;
        int j = 0;
        int mini = INT_MAX, count = 0;
        string ans = "";
        for(int i = 0; i < s.length(); i++) {
            
            if(mp1.count(s[i]))
                mp2[s[i]]++;
            
            if(mp1.count(s[i]) && mp2[s[i]] <= mp1[s[i]])
                count++;
            
            if(count == t.length()) {
                // cout<<i<<" ";
                while(!mp1.count(s[j]) || (mp1.count(s[j]) &&mp2[s[j]] > mp1[s[j]])) {
                    
                    if(mp1.count(s[j])&&mp2[s[j]] > mp1[s[j]] )
                        mp2[s[j]]--;
                    j++;
                }
                int len = i-j+1;
                if(len < mini) {
                ans = s.substr(j, len);
                mini = len;
                }
            }
            
        }
        return ans;
    }
};