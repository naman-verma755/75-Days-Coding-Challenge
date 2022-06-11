// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    bool dfs(int index, int prev, int visited[], vector<int>adj[]) {
        int color = 0;
        if(prev == 2) 
            color = 1;
        else 
            color = 2;
        visited[index] = color;
        
        for(auto it : adj[index]) {
            if(visited[it] == -1) {
                if(!dfs(it, color, visited, adj))
                return false;
            }
            if(visited[it] != -1 && visited[it] == color)
            return false;
        }
        return true;
        
    }
 
	bool isBipartite(int V, vector<int>adj[]){
	    // Code here
	    int visited[V];
	    for(int i = 0; i < V; i++)
	    visited[i] = -1;
	    for(int i = 0; i < V; i++) {
	        if(visited[i] == -1) {
	            if(!dfs(i, 2, visited, adj))
	            return false;
	        }
	    }
	    return true;
	}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}  // } Driver Code Ends