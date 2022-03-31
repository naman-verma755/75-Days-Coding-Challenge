class Solution {
public:
    int recur(int i, int j, string text1, string text2) {
        
        int n = text1.length();
        int m = text2.length();
        if(i >= n || j >= m)
            return 0;
        
        if(text1[i] == text2[j]) {
            return recur(i+1, j+1, text1, text2) +1;
        }
        else
        {
            return max(recur(i+1, j, text1, text2), recur(i, j+1, text1, text2));
        }
        return 0;
    }
    int longestCommonSubsequence(string text1, string text2) {
        
         int n = text1.length(), m = text2.length();
        int dp[n+1][m+1];
        for(int i = 0; i <= n; i++)
            dp[i][0] = 0;
        for(int i = 0; i <= m; i++)
            dp[0][i] = 0;
        
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                if(text1[i-1] == text2[j-1])
                    dp[i][j] = dp[i-1][j-1] +1;
                else
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
//         for(int i = 0; i <= n; i++) {
//             for(int j = 0; j <= m; j++) {
//                 cout<<dp[i][j]<<" ";
                
//             }
        //     cout<<endl;
        // }
        return dp[n][m];
         // return recur(0, 0, text1, text2);
        
    }
};