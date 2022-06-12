class Solution {
public:
    void buildGraph(vector<int>adj[],  vector<vector<int>>& connections) {
        
        for(vector<int>&edge: connections) {
            int u = edge[0], v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
    }
    void func(int node, int parent, int tin[], int low[], vector<vector<int>>&ans, int &counter, vector<int>adj[]) {
        
        
        low[node] = counter;
        tin[node] = counter;
        counter++;
        
        for(auto it : adj[node]) {
            
            if(it == parent)
                continue;
            if(tin[it] == -1)
                func(it, node, tin, low, ans, counter, adj);
            low[node] = min(low[it], low[node]);
            
            if(low[it] > tin[node])
            {
                ans.push_back(vector<int>()={node, it});
            }
            
            
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
     
        vector<int>adj[n];
        buildGraph(adj, connections);
        int tin[n];  //keeping time of insertion
        int low[n];  //keeping lowest time of insertion
        int counter = 0;
        for(int i = 0; i < n; i++)
        tin[i] = low[i] = -1;
        vector<vector<int>>ans;
        func(0, -1, tin, low, ans, counter, adj);
        return ans;
        
    }
};