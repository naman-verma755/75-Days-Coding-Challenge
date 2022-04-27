class Solution {
public:
    
    void dfs(int node, vector<int>adj[], vector<int>&indices, vector<char>&characters, bool visited[], string &s) {
        
          visited[node] = true;
          characters.push_back(s[node]);
          indices.push_back(node);
        
          for(auto it : adj[node]) {
              if(!visited[it]) {
                  dfs(it, adj, indices, characters, visited, s);
              }
          }
    }
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        
        int size = s.length();
        vector<int>adj[size];
        
        for(int i = 0; i < pairs.size(); i++) {
            
              int u = pairs[i][0];
              int v = pairs[i][1];
              adj[u].push_back(v);
              adj[v].push_back(u);
        }
        
        bool visited[size];
        memset(visited, false ,sizeof(visited));
        for(int i = 0; i < size; i++) {
            
            if(!visited[i]) {
                
                vector<char>characters;
            vector<int>indices;
                
                dfs(i, adj, indices, characters, visited, s);
                sort(characters.begin(), characters.end());
                sort(indices.begin(), indices.end());
                
                for(int i = 0; i < indices.size(); i++) {
                    s[indices[i]] = characters[i];
                }
            }
            
        }
        return s;
    }
};