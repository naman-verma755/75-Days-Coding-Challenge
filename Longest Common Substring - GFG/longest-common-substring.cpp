// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    public:
    int func(int i, int j, string s1, string s2) {
        if(i >= s1.length() || j >= s2.length())
        return 0;
        
        
        int k = 0;
        
        if(s1[i] == s2[j])
        k = 1+func(i+1, j+1, s1, s2);
        
        k = max(k, max(func(i+1, j, s1, s2), func(i, j+1, s1, s2)));
        
        return k;
    }
    int longestCommonSubstr (string S1, string S2, int n, int m)
    {
        // your code here
        // return func(0, 0, S1, S2);
        int dp[S1.length()+1][S2.length()+1];
        for(int i = 0; i < S1.length(); i++) 
        dp[i][0] = 0;
        for(int i = 0; i < S2.length(); i++) 
        dp[0][i] = 0;
        int maxi = 0;
        for(int i = 1; i <= S1.length(); i++) {
            for(int j = 1; j <= S2.length(); j++) {
                if(S1[i-1] == S2[j-1])
                dp[i][j] = 1+dp[i-1][j-1];
                else
                dp[i][j] = 0;
                
                maxi = max(maxi, dp[i][j]);
            }
        }
        return maxi;
        
    }
};

// { Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n, m; cin >> n >> m;
        string s1, s2;
        cin >> s1 >> s2;
        Solution ob;

        cout << ob.longestCommonSubstr (s1, s2, n, m) << endl;
    }
}
// Contributed By: Pranay Bansal
  // } Driver Code Ends