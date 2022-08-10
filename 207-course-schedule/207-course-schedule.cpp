class Solution {
public:
    bool dfs(int node, vector<int>adj[], bool visited[], bool revisited[]) {
        
        visited[node] = true;
        revisited[node] = true;
        
        for(auto it : adj[node]) {
            if(!visited[it] && dfs(it, adj, visited, revisited)){
                return true;
            }else if(revisited[it])
                return true;
        }
        revisited[node] = false;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>adj[numCourses];
        for(vector<int>&task : prerequisites)
            adj[task[0]].push_back(task[1]);
        bool visited[numCourses], revisited[numCourses];
        for(int i = 0; i < numCourses; i++) 
            visited[i] = revisited[i] = false;
        
        
        for(int i = 0; i < numCourses; i++) {
            if(!visited[i] && dfs(i, adj, visited, revisited))
                return false;
        }
        return true;
    }
};