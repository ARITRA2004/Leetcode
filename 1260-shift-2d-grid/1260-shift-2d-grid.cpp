class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {

        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>>ans(n,vector<int>(m));

        int total = m*n;
        k = k%total;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){

                int curr_pos = i*m+j;

                int newPos = (curr_pos + k) % total;
                
                int newRow = newPos / m;
                int newCol = newPos % m;

                ans[newRow][newCol] = grid[i][j];
            }
        }
        return ans;
    }
};