// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool isCycle(int node, bool visited[], bool recstack[], vector<int>adj[]) {
        
        visited[node] = true;
        recstack[node] = true;
        
        for(auto it : adj[node]) {
            if(!visited[it]) {
                if(isCycle(it, visited, recstack, adj))
                return true;
            } else if(recstack[it]) {
                return true;
            }
        }
        recstack[node] = false;
        return false;
    }
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        
        bool recstack[V];
    bool visited[V];
    memset(recstack, false, sizeof(recstack));
    memset(visited, false, sizeof(visited));
    
    
    for(int i = 0; i < V; i++) {
        
        if(!visited[i]) {
            if(isCycle(i, visited, recstack, adj))
            return true;
        }
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