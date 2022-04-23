class Solution {
public:
    void dfs(int s, vector<vector<int>>& graph,  vector<int>&util, vector<vector<int>>&ans) {
        int V = graph.size();
        if(s == V-1) {
            
            ans.push_back(util);
           
        }
       
        for(auto it : graph[s]) {
            
                util.push_back(it);
                dfs(it, graph,  util, ans);
                util.pop_back();
            
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<vector<int>>ans;
        
        
        
        vector<int>util;
        util.push_back(0);
        dfs(0, graph, util, ans);
        return ans;
        
    }
};