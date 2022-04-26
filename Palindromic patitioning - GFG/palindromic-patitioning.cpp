// { Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    bool isPalindrome(string s) {
        
        int i = 0, j = s.length()-1;
        while(i < j) {
            if(s[i++] != s[j--])
            return false;
        }
        
        return true;
    }
    int find(string str, map<string, int>&mp) {
        
        if(str.length() <= 0)
        return 0;
        
        if(mp.count(str))
        return mp[str];
        int mini = INT_MAX;
        string res = "";
        for(int i = 0; i < str.length(); i++) {
            res += str[i];
            if(isPalindrome(res)) {
                int k = find(str.substr(i+1, str.length()), mp)+1;
                mini = min(mini, k);
            }
        }
        return mp[str] = mini;
    }
    int palindromicPartition(string str)
    {
        // code here
        map<string, int>mp;
        return find(str, mp)-1;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.palindromicPartition(str)<<"\n";
    }
    return 0;
}  // } Driver Code Ends