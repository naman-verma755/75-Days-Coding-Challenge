class Solution {
public:
    int func(int left, int right, string s, vector<vector<int>>&dp) {
        
        if(left == right && s[left] == s[right])
            return 1;
        if(left > right )
            return 0;
        if(dp[left][right] != -1)
            return dp[left][right];
        if(s[left] == s[right]) 
            return dp[left][right] =  func(left+1, right-1, s, dp)+2;
        else {
            return dp[left][right] = max(func(left+1, right, s, dp), func(left, right-1, s, dp));
        }
        
        return 0;
    }
    int longestPalindromeSubseq(string s) {
        
        // vector<vector<int>>dp(s.length(), vector<int>(s.length(), -1));
        // return func(0, s.length()-1, s, dp);
        
        int dp[s.length()][s.length()];
        
        for(int i = 0; i < s.length(); i++) 
            dp[i][i] = 1;
        for(int i = 0; i < s.length()-1; i++) 
            if(s[i] == s[i+1])
                dp[i][i+1] = 2;
            else
                dp[i][i+1] = 1;
        
        // for(int i = 0; i < s.length(); i++) {
            for(int len = 2; len < s.length(); len++) {
                
                for(int i=0,j=len; j < s.length(); i++, j++) {
                    
                    if(s[i] == s[j]) 
                        dp[i][j] = dp[i+1][j-1] + 2;
                    else {
                        dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
                    }
                    
                }
            }
        
        return dp[0][s.length()-1];
        
    }
};