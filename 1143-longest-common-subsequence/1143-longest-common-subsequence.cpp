class Solution {
public:
    
    
    int longestCommonSubsequence(string text1, string text2) {
        // vector<vector<int>>dp(text1.length(), vector<int>(text2.length(), -1));
        int len1 = text1.length();
        int len2 = text2.length();
        
        // int dp[len1+1][len2+1];
        // for(int i = 0; i <= len1; i++)
        //     dp[i][0] = 0;
        // for(int i = 0; i <= len2; i++)
        //     dp[0][i] = 0;
        vector<int>prev(len2+1, 0);
        
        
        for(int i = 1; i <= len1; i++) {
            vector<int>curr(len2+1);
            curr[0] = 0;
            for(int j = 1; j <= len2; j++) {
                if(text1[i-1] == text2[j-1]) 
                   curr[j] = 1 + prev[j-1];
                else
                    curr[j] = max(prev[j], curr[j-1]);
            }
            prev = curr;
        }
        return prev[len2];
    }
};