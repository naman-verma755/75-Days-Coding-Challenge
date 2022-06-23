class Solution {
public:
    bool isPalindromic(string s) {
        int i = 0, j = s.length()-1;
        while(i < j) {
            if(s[i] != s[j])
                return false;
            i++, j--;
        }
        
        return true;
    }
    
    int countSubstrings(string s) {
        
        int countPalindromicSubstrings = 0;
        
        for(int i = 0; i < s.length(); i++) {
            
            string subStr = "";
            
            for(int j = i; j < s.length(); j++) {
                subStr += s[j];
                if(isPalindromic(subStr))
                    countPalindromicSubstrings++;
            }
        }
        
        return countPalindromicSubstrings;
    }
};