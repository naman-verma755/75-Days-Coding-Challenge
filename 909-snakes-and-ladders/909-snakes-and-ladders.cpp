class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        int dp[(n*n)+1];
        
        int visited[(n*n)+1];
        for(int i = 1; i <= n*n; i++)
            visited[i] = false;
        int nu = n*n;
        int flag;
        if(n%2 == 0)
        flag = 0;
        else
            flag = 1;
        for(int i = 0; i<n; i++) {
            if(flag == 0)
            {
                for(int j = 0; j < n; j ++)
                    dp[nu--] = board[i][j];
            }
            if(flag == 1)
            {
                for(int j=n-1; j>=0; j--)
                    dp[nu--] = board[i][j];
            }
            if(flag == 0)
                flag = 1;
            else
                flag = 0;
        }
        // for(int i = 1; i<=n*n; i++)
        //     cout<<dp[i]<<" ";
        // cout<<endl;
        queue<int>q;
        q.push(1);
        visited[1] = true;
        int level = 0;
        while(!q.empty()) {
            int size = q.size();
            // cout<<"s="<<size<<endl;
            while(size>0) {
                int num = q.front();
                // cout<<num<<endl;
                if(num== (n*n))
                         return level;
                q.pop();
                // if(visited[num])
                // {
                //     size--;
                //     continue;
                // }
                // visited[num] = true;
                for(int i = 1; i<=6; i++) {
                    int fr = num+i;
                    // if(fr >= (n*n))
                    //      break;
                    if(fr<=n*n&&!visited[fr])
                    {
                        visited[fr] = true;
                    int e = fr;
                    if(dp[fr] != -1)
                        e = dp[fr];
                    // else
                    //     k = dp[i];
                        
                     
                        q.push(e);
                    }
                }
                size--;
            }
            level++;
        }
        return -1;
        
    }
};