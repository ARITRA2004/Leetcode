class Solution {
public:
    int count_possibilities(vector<int>& vis) {
            int count = 0;

            // Block 1: seats 2,3,4,5
            bool block1 = true;
            for (int i = 2; i <= 5; i++) {
                if (vis[i] == 1) {
                    block1 = false;
                    break;
                }
            }

            // Block 2: seats 4,5,6,7
            bool block2 = true;
            for (int i = 4; i <= 7; i++) {
                if (vis[i] == 1) {
                    block2 = false;
                    break;
                }
            }

            // Block 3: seats 6,7,8,9
            bool block3 = true;
            for (int i = 6; i <= 9; i++) {
                if (vis[i] == 1) {
                    block3 = false;
                    break;
                }
            }

            if (block1)
                count++;
            if (block2)
                count++;
            if (block3)
                count++;

            if (count == 3)
                return 2;

            if (count > 0)
                return 1;

            return 0;
        }

    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {

        int count = 0;

        unordered_map<int, vector<int>> matrix;

        for (auto seat : reservedSeats) {
            int row = seat[0];
            int col = seat[1];

            if(matrix.find(row) == matrix.end()){
                matrix[row] = vector<int>(11, 0);
            }
            matrix[row][col] = 1;
        }

        for (auto &row : matrix) {
            count += count_possibilities(row.second);
        }

        count += (n - matrix.size())*2;

        return count;
    }
};