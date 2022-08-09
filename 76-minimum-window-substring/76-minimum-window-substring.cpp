class Solution {
public:
    string minWindow(string s, string t) {
        
        map<char, int>mp1, mp2;
          int maxi = INT_MAX;
        string ans = "";
        for(char ch: t)
            mp1[ch]++;
        int count = 0;
        int itr1 = 0, itr2 = 0;
      
        while(itr1 < s.length()) {
            if(mp1.count(s[itr1]))
            mp2[s[itr1]]++;
            if(mp1.count(s[itr1]) && mp2[s[itr1]] <= mp1[s[itr1]])
            count++;
            
            if(count == t.length()) {
                // cout<<itr1<<" ";
                while(!mp1.count(s[itr2]) || mp2[s[itr2]] > mp1[s[itr2]]) {
                    
                    if(mp1.count(s[itr2]) && mp2[s[itr2]] > mp1[s[itr2]])
                        mp2[s[itr2]]--;
                    itr2++;
                }
                
                 if(maxi > (itr1-itr2+1)) {
                maxi = itr1-itr2+1;
                ans = s.substr(itr2, (itr1-itr2+1));
                  }
            }
           
            itr1++;
            
        }
        return ans;
    }
};