class Solution {
public:
    int find(int node, int parent[]) {
        if(node == parent[node])
            return node;
        return parent[node] = find(parent[node], parent);
    }
    void unionOf(int u, int v, int parent[], int rank[]) {
        if(rank[u] < rank[v]) {
            parent[u] = v;
        }
        else if(rank[v] < rank[u]) {
            parent[v] = u;
        }
        else
        {
            rank[u]++;
            parent[v] = u;
        }
            
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        
        int parent[n];
        int rank[n];
        for(int i = 0; i < n; i++)
        {
            parent[i] = i;
            rank[i] = 0;
        }
        int extraEdges = 0;
        for(int i = 0; i < connections.size(); i++) {
              int u = connections[i][0];
              int v = connections[i][1];
              int parentOfu = find(u, parent);
              int parentOfv = find(v, parent);
              
              if(parentOfu == parentOfv)
              {
                  extraEdges++;
                  continue;
              }
              unionOf(parentOfu, parentOfv, parent, rank);
              
        }
        int countComponents = 0;
        for(int i = 0; i < n; i++) {
            
            if(parent[i] == i)
                countComponents++;
           
        }
        if(extraEdges >= countComponents-1)
            return countComponents-1;
        else
            return -1;
        return 0;
        
        
    }
};