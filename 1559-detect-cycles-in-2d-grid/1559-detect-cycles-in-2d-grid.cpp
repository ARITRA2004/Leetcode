class Solution {
public:

    bool dfsCheck(int row, int col, char start_char,vector<vector<char>> &grid, vector<vector<int>> &vis, int parentRow, int parentCol){

        vis[row][col] = 1;

        int n = grid.size();
        int m = grid[0].size();

        int delRow[4] = {-1,0,+1,0};
        int delCol[4] = {0,+1,0,-1};

        for(int i=0;i<4;i++){
            int newRow = row + delRow[i];
            int newCol = col + delCol[i];

            if(newRow < 0 || newRow >= n || newCol < 0 || newCol >= m) {
                continue;
            }

            if(vis[newRow][newCol] == 0 && grid[newRow][newCol] == start_char){

                if(dfsCheck(newRow, newCol, start_char, grid, vis,row,col)) return true;
            }
            else if(vis[newRow][newCol] == 1 && grid[newRow][newCol] == start_char && (newRow != parentRow || newCol != parentCol)){
                return true;
            }
        }
        return false;
    }

    bool containsCycle(vector<vector<char>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>>vis(n,vector<int>(m,0));

        for(char ch='a';ch <= 'z';ch++){
            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    if(grid[i][j] == ch && vis[i][j] == 0){
                        if(dfsCheck(i,j,ch,grid,vis,-1,-1) == true) return true;
                    }
                }
            }
        }
        return false;
    }
};