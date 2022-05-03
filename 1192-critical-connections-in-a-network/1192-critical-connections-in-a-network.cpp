class Solution {
public:
    vector<vector<int>>ans; 
    void dfs(int node, int parent, int &counter, int low[], int tin[], vector<int>adj[], vector<bool>&visited) {
        
        visited[node] = true;
        low[node] = counter;
        tin[node] = counter;
        counter++;
        for(int vertex : adj[node]) {
            if(!visited[vertex]) {
                dfs(vertex, node, counter, low, tin, adj, visited);
                // if(node == 0 && vertex == 1) {
                //     cout<<low[vertex]<<" "<<tin[vertex]<<endl;
                // }
                if(low[vertex] > tin[node]) {
                    vector<int>k = {node, vertex};
                    ans.push_back(k);
                }
                else {
                    low[node] = min(low[node], low[vertex]);
                }
                // if(node == 0 && vertex == 1) {
                //     cout<<low[vertex]<<" "<<tin[vertex]<<endl;
                // }
            
            } else if(vertex != parent) {
                low[node] = min(low[node], low[vertex]);
            }
        }
        
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        
        vector<int>adj[n];
        for(vector<int>&edge : connections) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        int low[n];
        int tin[n];
        int counter = 1;
        
        vector<bool>visited(n, false);
        dfs(0, -1, counter, low, tin, adj, visited);
        
        return ans;
    }
};