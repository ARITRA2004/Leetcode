class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<char,int>mpp;

        for(int i=0;i<9;i++){
            int row = i;
            int col = i;

            for(int r = 0;r<9;r++){
                if(board[r][col] == '.') continue;
                if(mpp.find(board[r][col])!=mpp.end()){
                    return false;
                }
                mpp[board[r][col]]++;
            }
            mpp.clear();
            for(int c = 0;c<9;c++){

                if(board[row][c] == '.') continue;
                if(mpp.find(board[row][c]) != mpp.end()){
                    return false;
                }
                mpp[board[row][c]]++;
            }
            mpp.clear();
        }

        mpp.clear();

        int boxCount = 9;
        int box = 0;
        while (box < boxCount) {
            int rowStart = (box / 3) * 3;
            int colStart = (box % 3) * 3;
            for (int i = rowStart; i < rowStart + 3; i++) {
                for (int j = colStart; j < colStart + 3; j++) {
                    if (board[i][j] == '.') continue;
                    if (mpp.find(board[i][j]) != mpp.end()) {
                        return false;
                    }
                    mpp[board[i][j]]++;
                }
            }
            box++;
            mpp.clear();
        }
        return true;
    }
};