class Solution {
public:
    int func(int index, string s, vector<int>&dp) {
        
        int len = s.length();   // string length
        if(index == len)
            return 1;
        
        if(s[index] == '0')
            return 0;
        if(dp[index] != -1)
            return dp[index];
        int count = 0;
        
        count += func(index+1, s, dp);
        string ans = "";
        ans += s[index];
        if(index+1 < len)
        {
            ans += s[index+1];
            if(ans >= "10" && ans <= "26")
            count += func(index+2, s, dp);
        }
        return dp[index] = count;
    }
    int numDecodings(string s) {
        vector<int>dp(s.length(), -1);
        return func(0, s, dp);
    }
};