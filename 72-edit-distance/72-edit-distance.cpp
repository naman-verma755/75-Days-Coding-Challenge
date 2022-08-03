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
        vector<vector<int>>dp(word1.length(), vector<int>(word2.length(), -1));
        return func(0, 0, word1, word2, dp);
    }
};