class Solution {
public:
    int func(int i, int j, string word1, string word2, vector<vector<int>>&dp) {
        if(i == word1.length())
            return word2.length()-j;
        if(j == word2.length())
            return word1.length()-i;
        
        if(dp[i][j] != -1)
            return dp[i][j];
        if(word1[i] == word2[j]) {
           return dp[i][j] = func(i+1, j+1, word1, word2, dp);
        } else {
            int k1 = func(i+1, j+1, word1, word2, dp); // replace operation
            int k2 = func(i+1, j, word1, word2, dp);   // remove operation
            int k3 = func(i, j+1, word1, word2, dp);           // insertoperation
            return dp[i][j] = min(k1, min(k2, k3))+1;
        }
       
    }
    int minDistance(string word1, string word2) {
        // vector<vector<int>>dp(word1.length(), vector<int>(word2.length(), -1));
        int len1 = word1.length(), len2 = word2.length();
        int dp[len1+1][len2+1];
        for(int i = 0; i <= len2; i++)
            dp[0][i] = i;
        for(int i = 0; i <= len1; i++)
            dp[i][0] = i;
        for(int i = 1; i <= len1; i++) {
            for(int j = 1; j <= len2; j++) {
                if(word1[i-1] == word2[j-1]) {
                    dp[i][j] = dp[i-1][j-1];
                }
                else {
                    dp[i][j] = min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1]))+1;
                }
            }
        }
        return dp[len1][len2];
    }
};