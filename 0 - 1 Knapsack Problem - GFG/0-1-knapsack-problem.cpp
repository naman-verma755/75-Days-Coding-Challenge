// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int findAns(int index, int W, int wt[], int val[], int n, vector<vector<int>>&dp) {
        
        if(W == 0 || index >= n)
        return 0;
        
        if(dp[index][W] != -1)
        return dp[index][W];
        int pick = 0;
        if(W-wt[index] >= 0)
        pick = findAns(index+1, W-wt[index], wt, val, n, dp) + val[index];
        int notPick = findAns(index+1, W, wt, val, n, dp);
        
        return dp[index][W] = max(pick, notPick);
    }
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Your code here
    //   vector<vector<int>>dp(n+1, vector<int>(W+1, -1));
    //   return findAns(0, W, wt, val, n, dp);
       int dp[n+1][W+1];
       for(int i = 0; i <= n; i++)
       dp[i][0] = 0;
       for(int i = 0; i <= W; i++)
       dp[0][i] = 0;
       
       for(int i = 1; i <= n; i++) {
           for(int j = 1; j <= W; j++) {
               int pick = 0, notPick = 0;
               if(j-wt[i-1] >= 0)
               pick = val[i-1]+dp[i-1][j-wt[i-1]];
               notPick = dp[i-1][j];
               
               dp[i][j] = max(pick, notPick);
           }
       }
       
       
       return dp[n][W];
       
    }
};

// { Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}  // } Driver Code Ends