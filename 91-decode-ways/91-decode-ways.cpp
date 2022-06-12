class Solution {
public:
    int decode(int index, string s, vector<int>&dp) {
        
        if(index == s.length())
            return 1;
        string ans = "";
        ans += s[index];
        if(ans == "0")
            return 0;
        if(dp[index] != -1)
            return dp[index];
        int way1 = decode(index+1, s, dp), way2 = 0;
        if(index+1 < s.length()) {
            ans += s[index+1];
            if(ans >= "1" && ans <= "26") 
            way2 = decode(index+2, s, dp);
        }
        return dp[index] = way1+way2;
        
    }
    int numDecodings(string s) {
        
        vector<int>dp(s.length(), -1);
        return decode(0, s, dp);
        
    }
};