class Solution {
public:
    int findNum(int i, string s, int val) {
       long long num = 0;
        
        while(i < s.length() && (s[i] >= '0' && s[i] <= '9')) {
            num = num*10 + (s[i]-'0');
            
        if(num > INT_MAX || num*val < INT_MIN)
        {
            if(val == -1)
                return INT_MIN;
            return INT_MAX;
        }
        
            i++;
        }
         // cout<<num<<" ";
        
        
        return num*val;
        
    }
    int myAtoi(string s) {
        int i = 0;
        
        for(;i < s.length(); ) {
            
            if(s[i] == '-' || s[i] == '+' || s[i] == '0') {
                int val = (s[i] == '-') ? -1 : 1;
                i++;
                
                while(i < s.length() && s[i] >= '0' && s[i] <= '9') {
                    if(s[i] >= '1' && s[i] <= '9')
                        return findNum(i, s, val);
                    i++;
                }
                return 0;
            }
            else if(s[i] >= '1' && s[i] <= '9')
                return findNum(i, s, 1);
            else if(s[i] == ' ' )
                i++;
            else 
                return 0;
        }
        return 0;
    }
};