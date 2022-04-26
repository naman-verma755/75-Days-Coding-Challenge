class Solution {
public:
    int find(int u, int parent[]) {
        if(u == parent[u])
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
    int minCostConnectPoints(vector<vector<int>>& points) {
        
        priority_queue<pair<int, pair< int, int>>, vector<pair<int, pair< int, int>>>, greater<pair<int, pair< int, int>>>>pq;
        
        for(int  i = 0; i < points.size()-1; i++) {
            for(int j= i+1; j < points.size(); j++) {
                int wt = (abs(points[i][0]-points[j][0])+abs(points[i][1]-points[j][1]));
                pq.push({wt, {i, j}});
            }
        }
        int size = points.size();
        int parent[size];
        int rank[size];
        for(int i = 0; i < size; i++){
            parent[i] = i;
            rank[i] = 0;
        }
        int sum = 0;

        while(!pq.empty()) {
            auto it = pq.top();
            pq.pop();
            int wt = it.first;
            int u = it.second.first;
            int v= it.second.second;
            
            int parentu = find(u, parent);
            int parentv = find(v, parent);
            if(parentu == parentv)
                continue;
            sum += wt;
            unionOf(parentu, parentv, parent, rank);
            
        }
        
        return sum;
    }
};