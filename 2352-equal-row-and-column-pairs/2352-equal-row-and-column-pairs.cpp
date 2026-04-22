class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {

        map<vector<int>,int>m;
        int pairs = 0;
        int n = grid.size();

        for(int i=0;i<n;i++){
            m[grid[i]]++;
        }

        for(int i=0;i<n;i++){
            vector<int>col;
            for(int j=0;j<n;j++){
                col.push_back(grid[j][i]);
            }
            pairs = pairs + m[col];
        }

        return pairs;
    }
};