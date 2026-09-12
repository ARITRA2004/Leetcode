class Solution {
public:

    int t[201][1001];

    int solve(int idx, vector<int> & nums, int target){
        if(target == 0){
            return 1;
        }

        if(idx >= nums.size() || target < 0){
            return 0;
        }

        if(t[idx][target] != -1){
            return t[idx][target];
        }

        int take_i = solve(0,nums,target - nums[idx]);
        int nottake_i = solve(idx+1, nums, target);

        return t[idx][target] = take_i + nottake_i;
    }

    int combinationSum4(vector<int>& nums, int target) {
        int n = nums.size();

        memset(t,-1,sizeof(t));

        return solve(0,nums,target);
    }
};