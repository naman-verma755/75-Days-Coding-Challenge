// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool dfs(int src, int parent, vector<int>adj[], bool visited[]) {
        
        visited[src] = true;
        // cout<<src<<" ";
        for(auto it : adj[src]) {
            if(it != parent) {
                if(visited[it] || dfs(it, src, adj, visited))
                return true;
            }
           
            }
        
        return false;
    }
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        bool visited[V+1];
        for(int i = 0; i < V; i++)
        visited[i] = false;
        
        for(int i = 0; i < V; i++) {
              if(!visited[i]) {
                  if(dfs(i, -1,adj, visited))
                  return true;
              }
        }
        
        return false;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}  // } Driver Code Ends