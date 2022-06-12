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
        
        vector<int>dp(s.length()+1);
        if(s[0] == '0')
            return 0;
        
        dp[0] = 1;
        dp[1] = 1;
        for(int i = 2; i <= s.length(); i++) {
            int way1 = 0, way2 = 0;
            string ans = "";
            ans += s[i-1];
            if(ans != "0")
                way1 = dp[i-1];
            ans = s[i-2]+ans;
            if(ans >= "1" && ans <= "26")
                way2 = dp[i-2];
            
            dp[i] = way1+way2;
        }
        return dp[s.length()];
//         return decode(0, s, dp);
        
    }
};