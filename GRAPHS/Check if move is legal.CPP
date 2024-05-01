// 1958. Check if Move is Legal

class Solution {
public:
    bool checkMove(vector<vector<char>>& board, int rMove, int cMove, char color) {
        int dx[8] = {1, -1, 0, 0, 1, 1, -1, -1}, dy[8] = {0, 0, 1, -1, -1, 1, -1, 1};

        for(int i=0; i<8; i++){
            int x = rMove, y = cMove;
            int count = 0;
            x = x + dx[i], y = y + dy[i];
            while(x < 8 and x >= 0 and y < 8 and y >= 0){
                if(board[x][y]=='.') 
                    break;
                if(board[x][y] != color){
                    count++;
                    x = x + dx[i];
                    y = y + dy[i];
                } else {
                    if(count >= 1)
                        return true;
                    break;
                }
            }
        }

        return false;
    }
};