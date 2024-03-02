// 1905. Count Sub Islands

class Solution {
public:
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    
    bool flag;
    void traverseIsland(int x, int y, int island_id, vector<vector<int>>& grid1, vector<vector<int>>& grid2){
        
        if(grid1[x][y] != island_id)
            flag = true;
        
        grid2[x][y] = -1;
        
        for(int i=0; i<4; i++){
            int newx = x + dx[i], newy = y + dy[i];
            if(newx >= 0 and newy >= 0 and newx < grid2.size() and newy < grid2[0].size() 
            and grid2[newx][newy]==1)
            {
                traverseIsland(newx, newy, island_id, grid1, grid2);
            }
        }
    }

    void assignIds(int x, int y, int island_id, vector<vector<int>>& grid1){
        grid1[x][y] = island_id;
        for(int i=0; i<4; i++){
            int newx = x + dx[i], newy = y + dy[i];
            if(newx >= 0 and newy >= 0 and newx < grid1.size() and newy < grid1[0].size() and grid1[newx][newy]==1)
                assignIds(newx, newy, island_id, grid1);
        }
    }

    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        // first assign id to each island in group 1
        int island_id = 2;
        for(int i=0; i<grid1.size(); i++){
            for(int j=0; j<grid1[0].size(); j++){
                if(grid1[i][j]==1){
                    assignIds(i, j, island_id, grid1);
                    island_id += 1;
                }
            }
        }
        // Now search for subislands
        int sub_islands = 0;
        for(int i=0; i<grid2.size(); i++){
            for(int j=0; j<grid2[0].size(); j++){
                if(grid2[i][j]==1 and grid1[i][j] >= 2){
                    flag = false;
                    traverseIsland(i, j, grid1[i][j], grid1, grid2);
                    if(!flag)
                        sub_islands++;
                }
            }
        }

        return sub_islands;
    }
};