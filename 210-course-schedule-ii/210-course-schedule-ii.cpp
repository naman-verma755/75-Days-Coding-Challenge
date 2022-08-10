class Solution {
public:
    bool dfs(int node, vector<int>adj[], bool visited[], bool revisited[], vector<int>&ans) {
        
        visited[node] = true;
        revisited[node] = true;
        
        
        for(auto it : adj[node]) {
            if(!visited[it] && dfs(it, adj, visited, revisited, ans))
                return true;
            else if(revisited[it])
                return true;
        }
        ans.push_back(node);
        revisited[node] = false;
        return false;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>ans;
        vector<int>adj[numCourses];
        for(vector<int>&v : prerequisites)
            adj[v[0]].push_back(v[1]);
        bool visited[numCourses], revisited[numCourses];
        for(int i = 0; i < numCourses; i++)
            visited[i] = revisited[i] = false;
        
        for(int i = 0; i < numCourses; i++) {
            if(!visited[i] && dfs(i, adj, visited, revisited, ans)) 
                return vector<int>();
        }
        return ans;
    }
};