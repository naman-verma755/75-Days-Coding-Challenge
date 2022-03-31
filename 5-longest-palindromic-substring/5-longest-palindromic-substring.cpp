class Solution {
public:
    string longestPalindrome(string s) {
        
          int n = s.length();
        int dp[n][n];
        for(int i = 0; i < n; i++)
            dp[i][i] = 1;
        int maxi = 1;
        int start=0,end=0;
        for(int l = 1; l < n; l++) {
            for(int j = 0, k = j+l; k < n; k++, j++) {
                // cout<<j<<k<<" ";
                if(s[j] == s[k])
                {
                    if(l == 1)  {
                        dp[j][k] = 1;
                        if(k-j+1> maxi) {
                            start = j, end = k;
                            maxi = k-j;
                            }
                    }
                    else{
                        if(dp[j+1][k-1] == 1) {
                            dp[j][k] = 1;
                            if(k-j+1> maxi) {
                            start = j, end = k;
                            maxi = k-j;
                            }
                        }
                        else
                            dp[j][k] = 0;
                    }
                        // dp[j][k] = 2+dp[j+1][k-1];
                }
                else
                    dp[j][k] = 0;
            }
        }
  string ans ="";
        for(int i = start; i<=end; i++)
            ans +=s[i];
        return ans;
        
    }
};