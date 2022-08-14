class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        queue<pair<int, int>>q;
        int total = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 1 || grid[i][j] == 2)
                    total ++;
                if(grid[i][j] == 2) {
                
                    q.push({i,j});
                  
                }
            }
        }
        if(total == 0)
            return 0;
        int time = -1;
        int dir1[] = {-1, 1, 0, 0};
        int dir2[] = {0, 0, -1, 1};
        int count = 0;
        while(!q.empty()) {
            
            int k = q.size();
            count += k;
            while(k > 0) {
                
                int i = q.front().first;
                int j = q.front().second;
                
                q.pop();
                
                for(int it = 0; it < 4; it++)
                {
                    int x = dir1[it]+i, y = dir2[it]+j;
                    if(x <0 || y < 0 || x >= n || y >= m)
                        continue;
                
                    if(grid[x][y] == 1) {
                        grid[x][y] = 2;
                        q.push({x,y});
                    }
                }
                k--;
            }
            time++;
            
        }
        if(count == total)
        return time;
        else
            return -1;
        
    }
};