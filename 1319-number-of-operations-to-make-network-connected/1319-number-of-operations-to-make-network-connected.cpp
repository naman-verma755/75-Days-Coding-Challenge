class Solution {
public:
    int find(int u, int parent[]) {
        
        if(u == parent[u])
            return u;
        
        return parent[u] = find(parent[u], parent);
    }
    
    void unionOf(int u, int v, int rank[], int parent[]) {
        
        if(rank[u] < rank[v])
            parent[u] = v;
        else if(rank[v] < rank[u])
            parent[v] = u;
        else {
            rank[u]++;
            parent[v] = u;
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        
        
        int parent[n];
        int rank[n];
        for(int i = 0; i < n; i++) {
            parent[i] = i;
            rank[i] = 0;
        }
        
        int count = 0;
        for(vector<int>&edge: connections) {
            int sys1 = edge[0];
            int sys2 = edge[1];
            
            int parentU = find(sys1, parent);
            int parentV = find(sys2, parent);
            
            if(parentU == parentV)
            {
                count++;
                continue;
            }
            
            unionOf(parentU, parentV, rank, parent);
            
            
        }
        int components = 0;
        for(int i = 0; i < n; i++) {
            if(i == parent[i])
                components++;
        }
        // cout<<components<<" ";
        if(count >= components-1)
            return components-1;
        return -1;
        
        
    }
};