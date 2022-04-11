class Solution {
public:
    
    
    int numDistinct(string s, string t) {
        // vector<vector<int>>dp(s.length(), vector<int>(t.length(),-1));
        int mod = 1000000007;
        int size1 = s.length();
        int size2 = t.length();
        int dp[size1+1][size2+1];
        for(int i = 0; i <= size2; i++)
            dp[0][i] = 0;
        for(int i = 0; i <= size1; i++)
            dp[i][0] = 1;
        
        for(int i = 1; i <= size1; i++) {
            for(int j = 1; j <= size2; j++) {
                int a = 0;
                if(s[i-1] == t[j-1]) {
                    a = dp[i-1][j-1];
                }
                int b = dp[i-1][j];
                dp[i][j] = (a+b)%mod;
            }
        }
        
        return dp[size1][size2];
    }
};