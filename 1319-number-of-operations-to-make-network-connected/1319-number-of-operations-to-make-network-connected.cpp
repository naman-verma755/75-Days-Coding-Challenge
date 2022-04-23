class Solution {
public:
    int find(int u, int parent[]) {
        if(parent[u] == u)
            return u;
        
        return parent[u] = find(parent[u], parent); // path compression
    }
    
    void unionOf(int u, int v, int parent[], int rank[]) {
        
        if(rank[u] < rank[v]) 
            parent[u] = v;
        else if(rank[u] > rank[v])
            parent[v] = u;
        else {
            rank[u] ++;
            parent[v] = u;
        }
    }
    
    int makeConnected(int n, vector<vector<int>>& connections) {
        
        int rank[n];
        int parent[n];
        for(int i = 0; i < n; i++) {
            rank[i] = 0;
            parent[i] = i;
        }
        int extraEdges = 0;
        for(auto edge : connections) {
            
            int vertex1 = edge[0];
            int vertex2 = edge[1];
            
            int parent1 = find(vertex1, parent);
            int parent2 = find(vertex2, parent);
            if(parent1 == parent2) {
                extraEdges++;
                continue;
            }
            
            unionOf(parent1, parent2, parent, rank);
        }
        int disconnectedCom = -1;
        for(int i = 0; i < n; i++) {
            if(parent[i] == i)
                disconnectedCom++;
        }
        
        if(extraEdges >= disconnectedCom)
            return disconnectedCom;
        
        return -1;
        
    }
};