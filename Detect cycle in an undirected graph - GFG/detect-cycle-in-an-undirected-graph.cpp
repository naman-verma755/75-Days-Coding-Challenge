// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    
    bool isCyce(int node, int parent, vector<int>adj[], bool visited[]) {
        // cout<<node<<" ";
        visited[node] = true;
        
        for(int i = 0; i < adj[node].size(); i++) {
            if(adj[node][i] != parent) {
            if(visited[adj[node][i]] || isCyce(adj[node][i], node, adj, visited))
            return true;
         
            }
        }
        return false;
    }
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        
        bool visited[V];
        memset(visited, false, sizeof(visited));
    
        for(int i = 0; i < V; i++) {
            if(!visited[i]) {
              
            if(isCyce(i, -1, adj, visited))
            return true;
           
              }
        }
            // if(!visited[i] && !isCycle(i, -1,adj, visited));
            // return true;
        
    
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