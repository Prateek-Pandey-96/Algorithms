// 861. Score After Flipping Matrix

class Solution {
public:
    int getNum(vector<int>& vec){
        int n = vec.size(), num = 0;
        for(int i=n-1; i>=0; i--)
            num += vec[i]==1? pow(2, n-1-i): 0;
        return num;
    }
    void flip_row(vector<int>& row){
        int n = row.size();
        for(int i=0; i<n; i++)
            row[i] = !row[i];
    }
    void flip_col(vector<vector<int>>& grid, int col){
        int m = grid.size();
        for(int i=0; i<m; i++)
            grid[i][col] = !grid[i][col];
    }
    int matrixScore(vector<vector<int>>& grid) {
        // make each row start with a 1
        // then for each column try to maximize the number of 1's
        int m = grid.size(), n = grid[0].size();
        for(int i=0; i<m; i++){
            if(!grid[i][0])
                flip_row(grid[i]);
        }

        for(int j=1; j<n; j++){
            int count_one = 0;
            for(int i=0; i<m; i++){
                if(grid[i][j]==1)
                    count_one++;
            }
            if(m-count_one > count_one)
                flip_col(grid, j);
        }

        int sum = 0;
        for(int i=0; i<m; i++){
            sum += getNum(grid[i]);
        }

        return sum;
    }
};