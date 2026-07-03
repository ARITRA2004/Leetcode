class Solution {
public:

    bool findSafeWalk(vector<vector<int>>& grid, int health) {

        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>> dis(n,vector<int>(m,INT_MAX));
        deque<pair<int,int>>dq;

        dis[0][0] = grid[0][0];
        dq.push_front({0,0});

        int delRow[4] = {0,0,1,-1};
        int delCol[4] = {-1,1,0,0};

        while(!dq.empty()){
            auto [row,col] = dq.front();
            dq.pop_front();

            for(int i=0;i<4;i++){
                int newRow = row + delRow[i];
                int newCol = col + delCol[i];

                if(newRow >= 0 && newRow < n && newCol >= 0 && newCol < m){
                    int wt = grid[newRow][newCol];

                    if(dis[row][col] + wt < dis[newRow][newCol]){
                        dis[newRow][newCol] = dis[row][col] + wt;
                        if(wt == 0) dq.push_front({newRow,newCol});
                        else dq.push_back({newRow,newCol});
                    }
                }
            }

        }
        if(dis[n-1][m-1] < health) return true;
        return false;
    }
};