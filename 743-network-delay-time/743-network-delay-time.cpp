class Solution {
public:
    void buildGraph(vector<pair<int, int>>adj[], vector<vector<int>>&times) {
        
        for(auto it : times) {
            adj[it[0]].push_back({it[1], it[2]});
        }
    }
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        
        vector<pair<int, int>>adj[n+1];
        buildGraph(adj, times);
        int dist[n+1];
        
        for(int i = 1; i <= n; i++)
            dist[i] = INT_MAX;
        
        
        set<pair<int, int>>st;
        
        dist[k] = 0;
        st.insert({0, k});
        
        while(!st.empty()) {
            
            auto it = *(st.begin());
            st.erase(it);
            int u = it.second;
            int wt1 = it.first;
            
            for(auto itr : adj[u]) {
                int v = itr.first, wt2 = itr.second;
                
                if((wt1+wt2) < dist[v]) {
                    if(dist[v] != INT_MAX) 
                        st.erase({dist[v], v});
                    dist[v] = (wt1+wt2);
                    st.insert({dist[v], v});
                }
            }
        }
        int maxi = -1;
        for(int i = 1; i <=n; i++)
            maxi = max(dist[i], maxi);
        if(maxi == INT_MAX)
            return -1;
        return maxi;
    }
};