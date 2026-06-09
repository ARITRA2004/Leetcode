class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());

        int n = nums.size();
        long long diff = 1LL * (nums[n-1]-nums[0]);
        long long ans = 1LL * k * diff;

        return ans;
    }
};