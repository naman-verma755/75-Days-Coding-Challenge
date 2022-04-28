class Solution {
public:
       int func(int index, string s, string res, vector<int>&dp) {
        
        if(index >= s.length())
            return 1;
        
        if(s[index] == '0')
            return 0;
        if(dp[index] != -1)
            return dp[index];
        int count = 0;
        
        count += func(index+1, s, res, dp);
        if(index+1 < s.length()) {
            string re="";
            re = re+s[index];
            re = re + s[index+1];
        int num = stoi(re);
            if(num >= 1 && num <= 26)
                count += func(index+2, s, res, dp);
            }
        
        return dp[index] = count;
    }
    int numDecodings(string s) {
        
        vector<int>dp(s.length()+4, -1);
        int count = func(0, s, "", dp);
        return count;
        
    }
};