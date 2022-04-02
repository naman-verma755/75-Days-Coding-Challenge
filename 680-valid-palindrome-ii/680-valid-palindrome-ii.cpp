class Solution {
public:
    bool validPalindrome(string s) {
        
        int i = 0, j = s.length()-1;
        int flag1 = 0;
        while(i < j)
        {
            if(s[i] == s[j]) {
                i++;
                j--;
            }
            else
            {
                flag1++;
                i++;
            }
            
               if(flag1 > 1)
                   break;
            
        }
         i = 0, j = s.length()-1;
        int flag2 = 0;
        while(i < j)
        {
            if(s[i] == s[j]) {
                i++;
                j--;
            }
            else
            {
                flag2++;
                j--;
            }
            
               if(flag2 > 1)
                   break;
            
        }
        if(flag1 <= 1 || flag2 <= 1)
            return true;
        return false;
        
        
    }
};