// 79. Word Search

class Solution {
public:
    int m, n;
    int dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};
    bool DFS(vector<vector<char>>& board, string word, int idx, int row, int col){
        if(idx == word.length()-1)
            return true;
        char temp = board[row][col];
        board[row][col] = '#';


        for(int i=0; i<4; i++){
            int newx = row + dx[i], newy = col + dy[i];
            if(newx >= 0 and newx < m and newy >= 0 and newy < n and board[newx][newy]==word[idx+1]){
                bool isPossible = DFS(board, word, idx+1, newx, newy);
                if(isPossible)
                    return true;
            }
        }

        board[row][col] = temp;
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        m = board.size(), n = board[0].size();
        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++)
                if(board[i][j] == word[0])
                {   
                    if(DFS(board, word, 0, i, j))
                        return true;
                }
        
        return false;
    }
};