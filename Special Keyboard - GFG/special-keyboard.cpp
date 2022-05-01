// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    long long int optimalKeys(int N){
        // code here
        if(N <= 6)
        return N;
        
        long long dp[N+1];
        for(int i = 1; i <= 6; i++)
        dp[i] = i;
       
        
        for(int i = 7; i <= N; i++) {
            long long maxi = 0;
            for(int j = 2; j <= i-2; j++) {
                
                maxi = max(maxi, j*dp[i-j-1]);
            }
            dp[i] = maxi;
        }
        return dp[N];
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        cout<<ob.optimalKeys(N)<<"\n";
    }
    return 0;
}  // } Driver Code Ends