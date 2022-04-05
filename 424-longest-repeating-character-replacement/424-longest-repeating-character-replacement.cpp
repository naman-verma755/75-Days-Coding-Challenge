class Solution {
public:
    int characterReplacement(string s, int k) {
       
        int freq[27] = {};
        int most = INT_MIN;
        int ans = INT_MIN, left = 0;
        for(int i = 0; i < s.length(); i++) {
            freq[s[i]-'A'] ++;
            most = max(most, freq[s[i]-'A']);
            
            int extraChar = (i-left+1-most);
            if(extraChar > k) {
                freq[s[left]-'A']--;
                left++;
            }
            ans = max(ans,i-left+1);
            
        }
        return ans;
        
    }
};