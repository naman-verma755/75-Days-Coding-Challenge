// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
	public:
	   void func(string s, string res,  vector<string>&ans, vector<bool>&visited) {
	       if(res.length() == s.length())
	       {
	       ans.push_back(res);
	       return;
	       }
	       
	       for(int i = 0; i < s.length(); i++) {
	           if(!visited[i]) {
	               visited[i] = true;
	               func(s, res+s[i], ans, visited);
	               visited[i] = false;
	           }
	       }
	   }
		vector<string>find_permutation(string S)
		{
		    // Code here there
		    vector<string>ans;
		    vector<bool>visited(S.length(), false);
		    func(S,"", ans, visited);
		    sort(ans.begin(), ans.end());
		    return ans;
		}
};



// { Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}
  // } Driver Code Ends