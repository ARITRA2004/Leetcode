class Solution {
public:

    void bfs(int row, int col, vector<vector<char>> &grid, vector<vector<int>> &vis){

        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int,int>>q;

        q.push({row,col});
        vis[row][col] = 1;

        int delRow[4] = {-1,0,1,0};
        int delCol[4] = {0,1,0,-1};

        while(!q.empty()){
            int tempRow = q.front().first;
            int tempCol = q.front().second;
            q.pop();

            for(int i=0;i<4;i++){
                int newRow = tempRow + delRow[i];
                int newCol = tempCol + delCol[i];

                if(newRow < n && newRow >=0 && newCol < m && newCol >= 0 && vis[newRow][newCol] == 0 && grid[newRow][newCol] == '1'){
                    vis[newRow][newCol] = 1;
                    q.push({newRow,newCol});
                }
            }
        }    
    }

    int numIslands(vector<vector<char>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>>vis(n,vector<int>(m,0));
        int cnt = 0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j] == 0 && grid[i][j] == '1'){
                    cnt++;
                    bfs(i,j,grid,vis);
                }
            }
        }

        return cnt;
    }
};