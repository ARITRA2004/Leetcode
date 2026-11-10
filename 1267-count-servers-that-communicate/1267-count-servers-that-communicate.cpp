class Solution {
public:

    int bfs(int row, int col, vector<vector<int>> &vis, vector<vector<int>> &grid){
        
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int,int>> q;

        q.push({row, col});
        vis[row][col] = 1;

        int count = 0;

        while(!q.empty()){
        
            auto [r,c] = q.front();
            q.pop();

            // check entire row
            for(int j = 0; j < m; j++) {

                if(grid[r][j] == 1 && !vis[r][j]) {
                    vis[r][j] = 1;
                    q.push({r, j});
                    count++;
                }
            }

            // Check entire column
            for(int i = 0; i < n; i++) {

                if(grid[i][c] == 1 && !vis[i][c]) {
                    vis[i][c] = 1;
                    q.push({i, c});
                    count++;
                }
            }
        }

        return count;
    }

    int countServers(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n,vector<int>(m,0));

        int count = 0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 1 && !vis[i][j]){
                    int res = bfs(i,j,vis,grid);
                    
                    if(res > 0){
                        count += res + 1;
                    }
                }
            }
        }

        return count;
    }
};