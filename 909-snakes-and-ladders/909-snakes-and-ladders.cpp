class Solution {
public:
  
    int snakesAndLadders(vector<vector<int>>& board) {
        
          int n = board.size();
          int dp[(n*n)+1];
          bool flag = true;
          int k = 1;
          for(int i = n-1; i >= 0; i--) {
              if(flag) {
                  flag = !flag;
                  for(int j = 0; j < n; j++)
                      dp[k++] = board[i][j];
              }
              else {
                  flag = !flag;
                  for(int j = n-1; j >= 0; j--) 
                      dp[k++] = board[i][j];
              }
          }
        // for(int i = 1; i <= (n*n); i++) {
        //     cout<<dp[i]<<" ";
        // }
        // cout<<endl;
          bool visited[n*n+1];
        memset(visited, false, sizeof(visited));
          queue<int>q;
          q.push(1);
        int count = 0;
          while(!q.empty()) {
              k = q.size();
            
              while(k > 0) {
                  int top = q.front();
                  q.pop();
                  
            
                  visited[top] = true;
               
                  
                  
                  for(int j = 1; j <= 6; j++) {
                      int pos = j+top;
                     
                      if( dp[pos] != -1)
                          pos = dp[pos];
                     
                      if(pos >= (n*n))
                          return count+1;
                      if(!visited[pos])
                      q.push(pos);
                  }
                  k--;
              }
              count++;
          }
        return -1;
    }
};