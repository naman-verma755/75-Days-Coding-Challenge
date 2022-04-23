class Solution {
public:
    int find(int u, int parent[]) {
        
        if(parent[u] == u)
            return u;
        
        return parent[u] = find(parent[u], parent);
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
    int findCircleNum(vector<vector<int>>& isConnected) {
        
        int size = isConnected.size();
        int rank[size];
        int parent[size];
        
        for(int i = 0; i < size; i++) {
            rank[i] = 0;
            parent[i] = i;
        }
        
        for(int i = 0 ; i < size; i++) {
            for(int j = i+1; j < size; j++) {
                if(isConnected[i][j] == 1) {
                    
                    int parentU = find(i, parent);
                    int parentV = find(j, parent);
                    if(parentU == parentV)
                        continue;
                    
                    unionOf(parentU, parentV, parent, rank);
                }
            }
        }
        int count = 0;
        for(int i = 0; i < size; i++) {
           
            if(parent[i] == i)
                count++;
        }
        return count;
        
    }
};