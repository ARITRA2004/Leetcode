class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {

        int n = grid.size();
        int m = grid[0].size();

        vector<int>ans;

        for(vector <int>row:grid){
            for(int ele:row) ans.push_back(ele);
        }

        int mod = ans[0] % x;

        for(int nums:ans){
            if(nums % x != mod) return -1;
        }

        sort(ans.begin(),ans.end());

        int mid = ans[(m*n)/2];
        int operations = 0;

        for(int num:ans){
            operations += abs(num - mid);
        }

        return operations/x;
    }
};