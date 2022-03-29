class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        
        int dir1[9] = {-1, -1, -1, 0, 1, 1, 1, 0};
        int dir2[9] = {-1, 0, 1, 1, 1, 0, -1, -1};
        
       
        
        int rows = board.size(), columns = board[0].size();
        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < columns; j++) {
                // cout<<i<<j<<endl;
                  int countOnes = 0;
                     int countZeroes = 0;
                 for(int k = 0; k< 8; k++) {
                     int x = i+dir1[k];
                     int y = j+dir2[k];
                   // cout<<x<<y<<" ";
                    
                     if(x >= 0 && x <rows && y >=0 && y < columns) {
                         if(board[x][y] == 1 || board[x][y] ==3) {
                             countOnes++;
                         }
                         else if(board[x][y] == 0 || board[x][y] == 2)
                             countZeroes++;
                     }
            
           
                  }
                if(board[i][j] == 0)
                {
                    if(countOnes == 3)
                        board[i][j] = 2;
                }
                if(board[i][j] == 1)
                {
                    if(countOnes > 3)
                        board[i][j] = 3;
                    else if(countOnes < 2)
                        board[i][j] = 3;
                }
        }
        }
        for(int i =0 ; i< rows; i++)
        {
            for(int j = 0; j < columns; j++) {
                if(board[i][j] == 2)
                    board[i][j] = 1;
                if(board[i][j] == 3)
                    board[i][j] = 0;
            }
        }
        
        
    }
};