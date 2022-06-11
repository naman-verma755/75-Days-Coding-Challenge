// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
    public:
    void buildGraph(int i, string dict[], vector<int>adj[]) {
        
        string s1 = dict[i];
        string s2 = dict[i+1];
        
        for(int i = 0; i < min(s1.length(), s2.length()); i++) {
            if(s1[i] != s2[i]) {
                adj[s1[i]-'a'].push_back(s2[i]-'a');
                break;
            }
        }
    }
    void dfs(int index, vector<int>adj[], bool visited[], stack<char>&st) {
        
        visited[index] = true;
        
        
        for(auto it : adj[index]) {
            if(!visited[it]) 
            dfs(it, adj, visited, st);
        }
        st.push('a'+index);
    }
    string findOrder(string dict[], int N, int K) {
        //code here
        
        
        vector<int>adj[K];
        
        for(int i = 0; i < N-1; i++) {
            buildGraph(i, dict, adj);
        }
        bool visited[K];
        memset(visited, false, sizeof(visited));
        
        stack<char>st;
        for(int i = 0; i < K; i++) {
            
             if(!visited[i])
             dfs(i, adj, visited, st);
        }
        
        string ans = "";
        while(!st.empty()) {
            ans += st.top();
            st.pop();
        }
        // cout<<ans<<endl;
        return ans;
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