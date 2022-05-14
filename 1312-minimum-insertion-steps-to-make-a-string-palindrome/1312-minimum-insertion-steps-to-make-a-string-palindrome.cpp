class Solution {
public:
    int func(int i, int j, string s, vector<vector<int>>&dp) {
        
        if(i > j)
            return 0;
        if(i == j)
            return 0;
        if(dp[i][j] != -1)
            return dp[i][j];
        
        if(s[i] == s[j]) {
            return dp[i][j] = func(i+1, j-1, s, dp);
        }
        else {
            return dp[i][j] = min(func(i+1, j, s, dp)+1, func(i, j-1, s, dp)+1);
        }
    }
    int minInsertions(string s) {
        
        // vector<vector<int>>dp(s.length()+1, vector<int>(s.length()+1, -1));
        // int maxi = func(0, s.length()-1, s, dp);
        // return maxi;
        
        int length = s.length();
        int dp[length+1][length+1];
        
        for(int i = 0; i <= length; i++) {
            dp[0][i] = 0;
            dp[i][length] = 0;
        }
        
        for(int i = 1; i <= length; i++) {
            for(int j = length-1; j >= 0; j--) {
                
                if(s[i-1] == s[j]) {
                    // dp[i][j] = min(dp[i-1][j], dp[i][j+1]);
                    dp[i][j] = dp[i-1][j+1]+1;
                }
                else
                    dp[i][j] = max((dp[i-1][j]), (dp[i][j+1]));
            }
        }
//          for(int i = 0; i <= length; i++) {
//             for(int j = 0; j <= length; j++) {
                
//                 cout<<dp[i][j]<<" ";
//             }
//              cout<<endl;
//         }
       
        
        return length-dp[length][0];
        
    }
};