class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(),nums.end());

        // 1,2,-1,4,-5
        // -5, -1, 1,2,4;
        int n = nums.size();
        int res = max({(nums[0]*nums[1]*nums[2]),(nums[n-3]*nums[n-2]*nums[n-1]),(nums[0]*nums[1]*nums[n-1]),(nums[0]*nums[n-2]*nums[n-1])});

        return res;
    }
};