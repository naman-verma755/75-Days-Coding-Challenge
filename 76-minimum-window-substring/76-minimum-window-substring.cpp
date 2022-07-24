class Solution {
public:
    string minWindow(string s, string t) {
        map<char, int>mp1, mp2;
        for(char ch : t)
            mp1[ch]++;
        
        int count = 0;
        int i = 0, j =0;
        string ans = "";
        int len = INT_MAX;
        while(j < s.length()) {
            
            if(mp1.count(s[j]))
                mp2[s[j]]++;
            if(mp1.count(s[j]) && mp2[s[j]] <= mp1[s[j]])
                count++;
            
            if(count == t.length()) {
                // cout<<"ye";
                 
                // cout<<i<<" "<<j<<endl;
                while(!mp1.count(s[i]) || mp2[s[i]] > mp1[s[i]]) {
                    
                    if(mp1.count(s[i]) && mp2[s[i]] > mp1[s[i]])
                        mp2[s[i]]--;
                    
                    i++;
                }
                if(j-i+1 < len) {
                    len = j-i+1;
                    ans = s.substr(i, j-i+1);
                }
                
               
                
            }
            j++;
        }
        return ans;
    }
};