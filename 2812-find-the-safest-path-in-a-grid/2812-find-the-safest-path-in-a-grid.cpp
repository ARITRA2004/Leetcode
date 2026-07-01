class Solution {
public:

    void bfs(vector<vector<int>> &grid, vector<vector<int>>&dis){
        queue<pair<int,int>>q;

        int n = grid.size();

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 1){
                    dis[i][j] = 0;
                    q.push({i,j});
                }
            }
        }

        int delRow[4] = {-1,1,0,0};
        int delCol[4] = {0,0,-1,1};

        while(!q.empty()){
            auto [row,col] = q.front();
            q.pop();

            for(int i=0;i<4;i++){
                int newRow = row + delRow[i];
                int newCol = col + delCol[i];

                if(newRow >= 0 && newRow < n && newCol >= 0 && newCol < n && dis[newRow][newCol] == INT_MAX){
                    dis[newRow][newCol] = dis[row][col] + 1;
                    q.push({newRow,newCol});
                }
            }
        }
    }

    bool isValid(vector<vector<int>> &dis, int mid){
        int n = dis.size();

        if(dis[0][0] < mid) return false;
        queue<pair<int,int>>q;
        vector<vector<int>>vis(n,vector<int>(n,false));

        q.push({0,0});
        vis[0][0] = true;

        int delRow[4] = {-1,1,0,0};
        int delCol[4] = {0,0,-1,1};

        while(!q.empty()){
            auto [row,col] = q.front();
            q.pop();

            if(row == n-1 && col == n-1) return true;

            for(int i=0;i<4;i++){
                int newRow = row + delRow[i];
                int newCol = col + delCol[i];

                if(newRow >= 0 && newRow < n && newCol >= 0 && newCol < n && dis[newRow][newCol] >= mid && !vis[newRow][newCol]){
                    vis[newRow][newCol] = true;
                    q.push({newRow,newCol});
                }
            }
        }
        return false;
    }

    int maximumSafenessFactor(vector<vector<int>>& grid) {
        

        int n = grid.size();
        if(grid[0][0] || grid[n-1][n-1]) return 0;

        vector<vector<int>>dis(n,vector<int>(n,INT_MAX));

        bfs(grid,dis);

        int low = 1;
        int high = 2*(n-1);

        while(low<=high){
            int mid = (low+high)/2;

            if(isValid(dis,mid) == true){
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
        return high;
    }
};