class Solution {
public:
    int func(int clip, int length, int n,  vector<vector<int>>&dp) {
        
        if(length == n)
            return 0;
        
        if(length > n)
            return INT_MAX;
        if(dp[clip][length] != -1)
            return dp[clip][length];
        int a =  func(clip, length+clip, n, dp);
        int b =  func(length, length+length, n, dp);
        if( a == INT_MAX && b == INT_MAX)
            return dp[clip][length] = a;
        if(a == INT_MAX && b != INT_MAX)
            return dp[clip][length] = b+2;
        if(a != INT_MAX && b == INT_MAX)
            return dp[clip][length] = a+1;
        
         
        return dp[clip][length] = min(a+1,b+2);
    }
    int minSteps(int n) {
        if(n == 1)
            return 0;
        vector<vector<int>>dp(n+3, vector<int>(n+3, -1));
        
        int count = func(1, 1, n, dp)+1;
        return count;
    }
};