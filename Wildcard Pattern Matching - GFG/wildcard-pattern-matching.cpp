// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
  public:
/*You are required to complete this method*/
    bool findMatch(int i, int j, string pattern, string str) {
        
        if(i == pattern.length() && j == str.length())
        return true;
        
        if(i >= pattern.length() && j < str.length())
        return false;
        
        if(j >= str.length()) {
            bool flag = true;
            
            for(int it = i; it < pattern.length(); it++)
            {
                if(pattern[it] != '*')
                {
                    flag = false;
                    break;
                }
            }
            return flag;
        }
        
        if(pattern[i] == str[j] || pattern[i] == '?') 
        return findMatch(i+1, j+1, pattern, str);
        
        if(pattern[i] == '*')
        return findMatch(i+1, j, pattern, str) || findMatch(i, j+1, pattern, str);
        
        return false;
    }
    int wildCard(string pattern,string str)
    {
        
       int pLength = pattern.length();
       int strLength = str.length();
        
        bool dp[pLength+1][strLength+1];
        memset(dp, false, sizeof(dp));
        dp[0][0] = true;
        
        for(int i = 1; i <= pLength; i++) {
            if(pattern[i-1] == '*')
            dp[i][0] = true;
            else
            break;
        }
        for(int i = 1; i <= pLength; i++) {
            for(int j = 1; j <= strLength; j++) {
                if(pattern[i-1] == str[j-1] || pattern[i-1] == '?')
                dp[i][j] = dp[i-1][j-1];
                else if(pattern[i-1] == '*') 
                dp[i][j] = dp[i-1][j] || dp[i][j-1];
                else
                dp[i][j] = false;
            }
        }
        return dp[pLength][strLength];
        // return findMatch(0, 0, pattern, str);
        
    }
};

// { Driver Code Starts.
int main()
{
   int t;
   cin>>t;
   while(t--)
   {
           string pat,text;
           cin>>pat;
cin.ignore(numeric_limits<streamsize>::max(),'\n');
           cin>>text;
           Solution obj;
           cout<<obj.wildCard(pat,text)<<endl;
   }
}
  // } Driver Code Ends