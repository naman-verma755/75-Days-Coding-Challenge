class Solution {
public:
   
    int longestCommonSubsequence(string text1, string text2) {
        int size1 = text1.length();
        int size2 = text2.length();
       
        // int dp[size1+1][size2+1];
        
        vector<int>prev(size2+1,0);
        // for(int i = 0; i <= size2; i++) {
        //     dp[0][i] = 0;
        // }
        // for(int i = 0; i <= size1; i++) {
        //     dp[i][0] = 0;
        // }
        for(int i = 1; i <= size1; i++) {
            vector<int>curr(size2+1,0);
            for(int j = 1; j <= size2; j++) {
                if(text1[i-1] == text2[j-1]){
                    curr[j] = 1 + prev[j-1];
                }
                else {
                    curr[j] = max(prev[j], curr[j-1]);
                }
            }
            prev = curr;
        }
        
        
       return prev[size2];
        
    }
};