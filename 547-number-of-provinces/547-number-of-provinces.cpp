class Solution {
public:
    int find(int node, int parent[]) {
        if(node == parent[node])
            return node;
        return parent[node] = find(parent[node], parent);
    }
    void unionOf(int u, int v, int rank[], int parent[]) {
        if(rank[u] < rank[v]) {
            parent[u] = v;
        }
        else if(rank[u] > rank[v])
        {
            parent[v] = u;
        }
        else
        {
            rank[u]++;
            parent[v] = u;
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        int parent[n];
        int rank[n];
        for(int i = 0; i < n; i++) {
            parent[i] = i;
            rank[i] = 0;
        }
        
        for(int i = 0; i < n; i++) {
            for(int j = i+1; j < n; j++) {
                if(isConnected[i][j] == 1) {
                 int pt1 = find(i, parent);
                 int pt2 = find(j, parent);
                if(pt1 == pt2)
                    continue;
                unionOf(pt1, pt2, rank, parent);
                }
            }
        }
        int count = 0;
      
        for(int i = 0; i < n; i++)
            if(parent[i] == i)
                count ++;
        return count;
        
    }
};