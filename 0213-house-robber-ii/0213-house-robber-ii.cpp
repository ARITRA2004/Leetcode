class Solution {
public:

    int helper(vector<int>& nums, int st, int end){
        int n = end - st + 1;

        int dp[100] = {0};

        dp[0] = nums[st];
        dp[1] = max(nums[st+1],dp[0]);

        for(int i=2;i<n;i++){
            dp[i] = max(dp[i-2] + nums[st+i] , dp[i-1]);
        }

        return dp[n-1];
    }

    int rob(vector<int>& nums) {

        if(nums.size() == 1){
            return nums[0];
        }

        if(nums.size() == 2){
            return max(nums[0],nums[1]);
        }

        int n = nums.size();

        return max(helper(nums,0,n-2),helper(nums,1,n-1));
    }
};