class Solution {
public:
    
    int func(int index, string s, vector<int>&dp) {
        
        if(index >= s.length())
            return 1;
        
        if(s[index] == '0')
            return 0;
        
        if(dp[index] != -1)
            return dp[index];
        int way1 = func(index+1, s, dp);
        int way2 = 0;
        string st = s.substr(index, 2);
        // cout<<st<<" ";
        if(index+1 < s.length() && st >= "1" && st <= "26")
            way2 = func(index+2, s, dp);
        
        return dp[index] = way1+way2;
    }
    int numDecodings(string s) {
        
        vector<int>dp(s.length(), -1);
        
        return func(0, s, dp);
    }
};