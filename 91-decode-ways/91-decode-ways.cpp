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
        vector<int>dp(s.length()+1, 0);
        dp[0] = 1;
        for(int i = 1; i <= s.length(); i++) {
            int count = 0;
            if(s[i-1] != '0') {
                count += dp[i-1];
            }
            string ans = "";
            ans += s[i-1];
            if(i-2 >= 0) {
                ans = s[i-2]+ans;
                if(ans >= "1" && ans <= "26") 
                    count += dp[i-2];
            }
            dp[i] = count;
        }
        return dp[s.length()];
        // return func(0, s, dp);
    }
};