class Solution {
public:
    bool dfs(int node, int prev, vector<vector<int>>&graph, vector<int>&visited) {
        
        if(prev == -1)
            visited[node] = 1;
        if(prev == 1)
            visited[node] = 2;
        else
            visited[node] = 1;
        
        for(auto it : graph[node]) {
            
            if(visited[it] != -1 ) {
                if(visited[node] == visited[it])
                return false;
            }
            else if(!dfs(it, visited[node], graph, visited))
                return false; 
            
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        
        int size = graph.size();
        
        vector<int>visited(size, -1);
        for(int i = 0; i < size; i++) {
            if(visited[i] == -1) {
                
                if(!dfs(i, -1, graph, visited))
                    return false;
                
            }
        }
        return true;
    }
};