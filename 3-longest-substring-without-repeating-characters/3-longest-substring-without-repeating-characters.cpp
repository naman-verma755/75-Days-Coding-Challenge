class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        map<char, int>mp;
        
        int longestSubstringLength = 0;
        int left = 0;
        for(int i = 0; i < s.length(); i++ ) {
            
            mp[s[i]]++;
            
            while(mp[s[i]] > 1) {
                mp[s[left]]--;
                left ++;
            }
            longestSubstringLength = max(longestSubstringLength, (i-left+1));
        }
        return longestSubstringLength;
        
    }
};