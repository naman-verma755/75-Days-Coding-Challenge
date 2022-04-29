class Solution {
public:
    int findParent(int u, int parent[]) {
        if(u == parent[u])
            return u;
        
        return parent[u] = findParent(parent[u], parent);
    }
    
    void unionOf(int u, int v, int parent[], int rank[]) {
        
        if(rank[u] < rank[v]) 
            parent[u] = v;
        else if(rank[v] < rank[u]) 
            parent[v] = u;
        else {
            rank[u] ++;
            parent[v] = u;
        }
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        
        int n = edges.size();
        
        int parent[n+1];
        int rank[n+1];
        for(int i = 1; i <= n; i++) {
            parent[i] = i;
            rank[i] = 0;
        }
        
        vector<int>ans(2,0);
        for(vector<int>&edge : edges) {
            
            int u = findParent(edge[0], parent);
            int v = findParent(edge[1], parent);
            
            if(u == v)
            {
                ans[0] = edge[0];
                ans[1] = edge[1];
                continue;
            }
            
            
            unionOf(u, v, parent, rank);
        }
        
        return ans;
    }
};