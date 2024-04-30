// 419. Battleships in a Board

class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        int count = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]=='X' && (i==m-1 || board[i+1][j]=='.') && (j==n-1 || board[i][j+1]=='.'))
                    count++;
            }
        }
        return count;
    }
};  