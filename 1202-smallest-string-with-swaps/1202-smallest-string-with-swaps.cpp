class Solution {
public:
    int find(int u, int parent[]) {
        if(u == parent[u])
            return u;
        
        return parent[u] = find(parent[u], parent);
    }
    
    void unionOf(int u, int v, int parent[], int rank[]) {
        if(rank[u] < rank[v]) {
            parent[u] = v;
        }
        else if(rank[v] < rank[u]) {
            parent[v] = u;
        }
        else {
            rank[u] ++;
            parent[v] = u;
        }
    }
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        
        
        int size = s.length();
        int parent[size];
        int rank[size];
        for(int i = 0; i < size; i++) {
            parent[i] = i;
            rank[i] = 0;
        }
        
        for(int i = 0; i < pairs.size(); i++) {
            
            int parentu = find(pairs[i][0], parent);
            int parentv = find(pairs[i][1], parent);
            
            if(parentu == parentv)
                continue;
            
            unionOf(parentu, parentv, parent,rank);
        }
        map<int , vector<int>>mp;
        for(int i = 0; i < size; i++)
        {
            int root = find(i, parent);
            mp[root].push_back(i);
        }
        string str(s.length(), ' ');
        for(auto it : mp) {
            vector<int>indices = it.second;
            vector<char>characters;
            for(int i = 0; i < indices.size(); i++)
                characters.push_back(s[indices[i]]);
            sort(characters.begin(), characters.end());
            
            for(int i = 0; i < indices.size(); i++) {
                str[indices[i]] = characters[i];
            }
            
        }
        return str;
    }
};