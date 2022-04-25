class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        int dp[(n*n+4)];
        
        
        int flag = 1;
        int index = 1;
        for(int i = n-1; i >= 0; i--) {
            // cout<<index<<" ";
            if(flag == 1) {
                for(int j = 0; j < n; j++) 
                {
                    dp[index] = board[i][j];
                    index++;
                }
                flag = 0;
            }
            else {
                for(int j = n-1; j >= 0; j--) 
                {
                    dp[index] = board[i][j];
                    index++;
                }
                flag = 1;
            }
            
        }
        // cout<<endl<<endl;
        // for(int i = 1; i <= n*n; i++)
        //     cout<<i<<"="<<dp[i]<<"   ";
        
        queue<int>q;
        q.push(1);
        
        bool visited[n*n+2];
        memset(visited, false, sizeof(visited));
        int step = 0;
        int target = n*n;
        while(!q.empty()) {
            int size = q.size();
            while(size > 0) {
                
                int num = q.front();
                q.pop();
                if(num == target)
                    return step;
                visited[num] = true;
                
                for(int i = 1; i <= 6; i++) {
                    int next = num+i;
                    if(next <= (n*n)) {
                    if(dp[next] != -1)
                        next = dp[next];
                    // cout<<next<<" ";
                    if( !visited[next]) 
                        q.push(next);
                    }
                }
                size--;
            }
            step++;
        }
        
        return -1;
        

        
        
        
        
        
        
        
        
        
        
        
        
        
        
    }
};