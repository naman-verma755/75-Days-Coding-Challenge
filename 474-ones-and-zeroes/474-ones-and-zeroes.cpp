class Solution {
public:
    
    int func(int index, int m, int n, vector<string>&strs,vector<vector<vector<int>>>&dp) {
        
        if(index >= strs.size())
            return 0;
        // if(m < 0 || n < 0)
        //     return 0;
        // if(m == 0 && n == 0)
        //     return 1;
        // cout<<strs[index]<<" ";
        if(dp[index][m][n] != -1)
            return dp[index][m][n];
            
        int countOnes = 0;
        int countZeroes = 0;
        for(char ch : strs[index])
            if(ch == '0')
                countZeroes++;
            else
                countOnes++;
        int sum = 0;
        if(m-countZeroes >= 0 && n-countOnes >= 0)
            sum += func(index+1, m-countZeroes, n-countOnes, strs, dp)+1;
        sum = max(sum,func(index+1, m, n, strs, dp));
        return dp[index][m][n] = sum;
            
    } 
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<vector<int>>>dp(strs.size()+1, vector<vector<int>>(m+1, vector<int>(n+1,-1)));
        return func(0, m, n, strs, dp);
    }
};