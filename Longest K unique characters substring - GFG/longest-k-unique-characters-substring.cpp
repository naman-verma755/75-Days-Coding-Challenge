// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int longestKSubstr(string s, int k) {
    // your code here
    int left = 0;
    int ans = 0;
    int freq[27] = {};
    int count = 0;
    for(int right = 0; right < s.length(); right++) {
        
        if(freq[s[right]-'a'] == 0)
        count ++;
        freq[s[right]-'a']++;
        while(count > k) {
            freq[s[left]-'a']--;
            if(freq[s[left]-'a'] == 0)
            count--;
            left++;
        }
        if(count == k)
        ans = max(ans, (right-left+1));
    }
    if(ans == 0)
    return -1;
    return ans;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int k;
        cin >> k;
        Solution ob;
        cout << ob.longestKSubstr(s, k) << endl;
    }
}
  // } Driver Code Ends