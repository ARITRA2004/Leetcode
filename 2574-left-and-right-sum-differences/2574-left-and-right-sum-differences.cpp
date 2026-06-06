class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();
        vector<int>suffixSum(n,0);

        suffixSum[n-1] = 0;
        for(int i=n-2;i>=0;i--){
            suffixSum[i] = suffixSum[i+1] + nums[i+1];
        }

        int prefixSum = 0;

        vector<int>ans;
        for(int i=0;i<n;i++){
            int diff = abs(prefixSum - suffixSum[i]);
            ans.push_back(diff);
            prefixSum = prefixSum + nums[i];
        }
        return ans;
    }
};