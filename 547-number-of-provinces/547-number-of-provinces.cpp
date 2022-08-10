class Solution {
public:
    int find(int a, int parent[]) {
        if(a == parent[a])
            return a;
        
        return parent[a] = find(parent[a], parent); 
    }
    void unionByRank(int a, int b, int parent[], int rank[]) {
        
       
        
        if(rank[a] < rank[b])
            parent[a] = b;
        else if(rank[b] < rank[a])
            parent[b] = a;
        else {
            rank[a]++;
            parent[b] = a;
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
//          for(int i = 0; i < n; i++)
//              cout<<parent[i]<<" ";
        
        for(int i = 0; i < n; i++) {
            for(int j = i+1; j < n; j++) {
                if(isConnected[i][j] == 1 ) 
                {

                     int a = find(i, parent);
                     int b = find(j, parent);
       
                     if(a == b)
                      continue;
                    unionByRank(a,b, parent, rank);
                }
            }
        }
       
        int count = 0;
        for(int i = 0; i < n; i++) {
            if(parent[i] == i)
                count++;
        }
        
        return count;
        
    }
};