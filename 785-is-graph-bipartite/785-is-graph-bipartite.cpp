class Solution {
public:
    bool dfs(int node, vector<vector<int>>& graph, int color, int colored[]) {
        
        
       
            colored[node] = color;
       // cout<<node<<" ";
        
        if(color == 1)
            color = 2;
        else
            color = 1;
        
        for(int it : graph[node]) {
        
            if(colored[it] == 0 && !dfs(it, graph, color, colored))
                 return false;
            else if(colored[it] == colored[node])
                    return false;
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        int colored[n];
        for(int i = 0; i < n; i++)
            colored[i] = 0;
     
        
        for(int i = 0; i < n; i++) {
            if(colored[i] == 0 && !dfs(i, graph, 1, colored))
                return false;
        }
        // for(int i = 0; i<n; i++)
        //     cout<<colored[i]<<" ";
        return true;
        
        
    }
};