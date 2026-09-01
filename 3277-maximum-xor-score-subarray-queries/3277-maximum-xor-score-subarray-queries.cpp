class Solution {
public:
    vector<int> maximumSubarrayXor(vector<int>& nums, vector<vector<int>>& queries) {

        int n = nums.size();
        int ans[n][n];

        // length 1
        for(int i=0;i<n;i++){
            ans[i][i] = nums[i];
        }

        //length 2 ..... n
        int length = 2;
        while(length <= n){
            for(int i=0;i<=n-length;i++){
                int j = i + length - 1;
                ans[i][j] = ans[i][j-1] ^ ans[i+1][j];
            }
            length++;
        }


        // now calucate the queries using the subarray dp concept

        int dp[n][n];

        // length 1
        for(int i=0;i<n;i++){
            dp[i][i] = nums[i];
        }

        // length 2
        for(int i=0;i<n-1;i++){
            dp[i][i+1] = max(ans[i][i+1],max(dp[i][i],dp[i+1][i+1]));
        }

        // length 3 .... n
        length = 3;
        while(length <= n){
            for(int i=0;i<=n-length;i++){
                int j = i + length - 1;
                dp[i][j] = max(ans[i][j],max(dp[i+1][j],dp[i][j-1]));
            }
            length++;
        }

        vector<int>q;

        for(int k=0;k<queries.size();k++){
            int i = queries[k][0];
            int j = queries[k][1];

            q.push_back(dp[i][j]);
        }
        
        return q;
    }
};