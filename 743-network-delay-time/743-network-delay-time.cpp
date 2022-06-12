class Solution {
public:
    void buildGraph(vector<vector<int>>& times, vector<pair<int, int>>adj[]) {
        
        for(vector<int>&edge: times) {
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];
            
            adj[u].push_back({v, wt});
        }
    }
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        
        vector<pair<int, int>>adj[n+1];
        buildGraph(times, adj);
        
        int dist[n+1];
        
        for(int i = 1; i <= n; i++)
            dist[i] = INT_MAX;
        
        set<pair<int, int>>st;
        
        dist[k] = 0;
        st.insert({0, k});
        
        while(!st.empty()) {
            
            pair<int, int>temp = *(st.begin());
            st.erase(temp);
            int u = temp.second;
            int wt1 = temp.first;
            
            for(auto it: adj[u]) {
                int v = it.first, wt2 = it.second;
                if((wt1+wt2) < dist[v]) {
                    
                    if(dist[v] != INT_MAX)
                        st.erase({dist[v], v});
                    dist[v] = (wt1+wt2);
                    st.insert({dist[v], v});
                }
            }
        }
        
        int minTime = -1;
        for(int i = 1; i <= n; i++)
            minTime = max(minTime, dist[i]);
        
        if(minTime == INT_MAX)
            return -1;
        return minTime;
        
    }
};