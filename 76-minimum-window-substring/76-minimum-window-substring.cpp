class Solution {
public:
    string minWindow(string s, string t) {
        
        
        int count = 0;
        map<char, int>mp, mp2;
        string ans = "";
        int maxLength = INT_MAX;
        for(char ch: t)
            mp[ch]++;
        int left = 0;
        for(int right = 0; right < s.length(); right++) {
            
            mp2[s[right]]++;
            if(mp.count(s[right]) && mp2[s[right]] <= mp[s[right]])
                count++;
            
            if(count == t.length()) {
                
                while(!mp.count(s[left]) || mp2[s[left]] > mp[s[left]]) {
                    if(mp2[s[left]] > mp[s[left]])
                    mp2[s[left]]--;
                left++;
                }
                  int len = right-left+1;
                if(len < maxLength) {
                    maxLength = len;
                ans = s.substr(left, len);
                }
            }
//             while(left < right && (count > t.length() || !mp.count(s[left])))
//             {
//                 if(mp.count(s[left]))
//                     count--;
                
//                 left++;
//             }
//             while(count > t.length()) {
                
//                 if(mp.count(s[left]))
//                     count--;
//                 left++;
//             }
            
            // if(count == t.length())
          
            // cout<<ans<<" ";
        }
         
        return ans;
    }
};