// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool dfs(int src, vector<int>adj[], bool visited[], bool restack[]) {
        
        visited[src] = true;
        restack[src] = true;
        
        
        for(auto it: adj[src]) {
            
            if(!visited[it]) {
                if(dfs(it, adj, visited, restack))
                return true;
            }
            else if(restack[it])
            return true;
        }
        restack[src] = false;
        return false;
        
    }
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        
        
        bool visited[V];
        bool restack[V];
        for(int i = 0; i < V; i++) {
            visited[i] = false;
            restack[i] = false;
        }
        
        for(int i = 0; i < V; i++) {
            if(dfs(i, adj, visited, restack))
            return true;
        }
        return false;
    }
};

// { Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}
  // } Driver Code Ends