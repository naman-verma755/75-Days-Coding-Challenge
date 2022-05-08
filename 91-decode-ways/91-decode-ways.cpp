class Solution {
public:
     
    int findWays(int index, string s,  vector<int>&dp ){
        if(index == s.length())
            return 1;
        
        if(s[index] == '0')
            return 0;
        
         if(dp[index] != -1)
             return dp[index];
        int count = 0;
        count += findWays(index+1, s, dp);
        string res = "";
        if(index+1 < s.length()) {
        res = res+s[index]+s[index+1];
        if(res >= "10" && res <= "26")
            count += findWays(index+2, s, dp);
        }
        
        return dp[index] = count;
        

    }
    int numDecodings(string s) {
        vector<int>dp(1000, -1);
        return findWays(0, s, dp);
    }
};