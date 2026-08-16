class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        // gap + cross = wall_size

        int wall_size = wall.size();

        int gap = 0;
        int cross = 0;

        unordered_map<int,int>mpp;
        int max_gap = 0;

        for(int i = 0; i < wall.size() ; i++){

            long long sum = 0;

            for(int j=0;j<wall[i].size()-1;j++){

                sum = sum + wall[i][j];
                mpp[sum]++;
                max_gap = max(max_gap,mpp[sum]);

            }
        }

        cross = wall_size - max_gap;

        return cross;
    }
};