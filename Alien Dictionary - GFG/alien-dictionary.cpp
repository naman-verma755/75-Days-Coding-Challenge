// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
    public:
    void buildGraph(string s1, string s2, vector<int>adj[]) {
        
        
        int i = 0, j = 0;
        while( i < s1.length() && j < s2.length()) {
            if(s1[i] != s2[j]) {
                adj[s1[i]-'a'].push_back(s2[j]-'a');
                return;
            }
            i++;
            j++;
        }
    }
    void dfs(int i , vector<int>adj[], bool visited[], vector<char>&v) {
        
        
        visited[i] = true;
        
        for(auto it : adj[i]) {
            if(!visited[it])
            dfs(it, adj, visited, v);
        }
        v.push_back(char(i+'a'));
    }
    string findOrder(string dict[], int N, int k) {
        //code here
        vector<int>adj[k];
        
        for(int i = 0; i < N-1; i++) {
                buildGraph(dict[i], dict[i+1], adj);
        }
        
        bool visited[k];
        memset(visited, false, sizeof(visited));
        
        vector<char>v;
        for(int i = 0; i < k; i++) {
            if(!visited[i])
            dfs(i, adj, visited, v);
        }
        string res = "";
        for(int i = 0; i < v.size(); i++) {
            res = v[i]+res;
        }
        // cout<<res;
        return res;
    }
};

// { Driver Code Starts.
string order;
bool f(string a, string b) {
    int p1 = 0;
    int p2 = 0;
    for (int i = 0; i < min(a.size(), b.size()) and p1 == p2; i++) {
        p1 = order.find(a[i]);
        p2 = order.find(b[i]);
        //	cout<<p1<<" "<<p2<<endl;
    }

    if (p1 == p2 and a.size() != b.size()) return a.size() < b.size();

    return p1 < p2;
}

// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        string dict[N];
        for (int i = 0; i < N; i++) cin >> dict[i];
        
        Solution obj;
        string ans = obj.findOrder(dict, N, K);
        order = "";
        for (int i = 0; i < ans.size(); i++) order += ans[i];

        string temp[N];
        std::copy(dict, dict + N, temp);
        sort(temp, temp + N, f);

        bool f = true;
        for (int i = 0; i < N; i++)
            if (dict[i] != temp[i]) f = false;

        if(f)cout << 1;
        else cout << 0;
        cout << endl;
    }
    return 0;
}
  // } Driver Code Ends