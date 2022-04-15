// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    public:
    
    int longestCommonSubstr (string S1, string S2, int n, int m)
    {
        // your code 
        int n1 = S1.length(), n2 = S2.length();
        int dp[n1][n2];
        int longest = INT_MIN;
        for(int i=0; i<n1; i++)
        {
            for(int j=0; j<n2; j++)
            {
                if(S1[i] == S2[j] && (i == 0 || j==0))
                {
                    dp[i][j] = 1;
                }
                else if(S1[i] == S2[j] )
                {
                    dp[i][j] = 1+dp[i-1][j-1];
                }
                else
                {
                    dp[i][j] = 0;
                }
                longest = max(longest,dp[i][j]);
                
            }
        }
        return longest;
        
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