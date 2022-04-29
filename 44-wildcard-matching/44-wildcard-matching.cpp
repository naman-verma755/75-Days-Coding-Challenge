class Solution {
public:
    bool isMatch(string str,string pattern) {
        
        
       int pLength = pattern.length();
       int strLength = str.length();
        
        bool dp[pLength+1][strLength+1];
        memset(dp, false, sizeof(dp));
        dp[0][0] = true;
        
        for(int i = 1; i <= pLength; i++) {
            if(pattern[i-1] == '*')
            dp[i][0] = true;
            else
            break;
        }
        for(int i = 1; i <= pLength; i++) {
            for(int j = 1; j <= strLength; j++) {
                if(pattern[i-1] == str[j-1] || pattern[i-1] == '?')
                dp[i][j] = dp[i-1][j-1];
                else if(pattern[i-1] == '*') 
                dp[i][j] = dp[i-1][j] || dp[i][j-1];
                else
                dp[i][j] = false;
            }
        }
        return dp[pLength][strLength];
        // return findMatch(0, 0, pattern, str);
        
    }
    
};