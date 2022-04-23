class Solution {
public:
    void buildGraph( vector<pair<int, int>>adj[], vector<vector<int>>& roads) {
        
        for(auto it : roads) {
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }
    }
    int countPaths(int n, vector<vector<int>>& roads) {
        long long mod = 1000000007;
        long long ways[n];
        // memset(ways, 1, sizeof(ways));
        long long dist[n];
        vector<pair<int, int>>adj[n];
        buildGraph(adj, roads);
        for(int i = 0; i < n; i++) {
            dist[i] = 1e18;
            ways[i] = 0;
        }
        
        set<pair<long long, long long>>st;
        dist[0] = 0;
        ways[0] = 1;
        st.insert({0, 0});
        
        
        while(!st.empty()) {
            
            auto it = *(st.begin());
            st.erase(it);
            long long u = it.second;
            long long wt1 = it.first;
            
            for(auto it : adj[u]) {
                long long v = it.first;
                long long wt2 = it.second;
                if((wt1+wt2) < dist[v]) {
                    
                    if(dist[v] != INT_MAX) {
                        st.erase({dist[v], v});
                    }
                    dist[v] = (wt1+wt2);
                    st.insert({dist[v], v});
                    ways[v] = ways[u];
                    
                }
                else if((wt1+wt2) == dist[v]) {
                    ways[v] =(ways[v]+ ways[u])%mod;
                }
            }
        }
        // for(int i = 0; i < n; i++)
        //     cout<<ways[i]<<" ";
        // if(ways[n-1] == 0)
        //     return 1;
        
        return ways[n-1];
    }
};