class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {

        vector<int>ans;

        sort(nums.begin(),nums.end()); // O(nlogn)

        auto lb = lower_bound(nums.begin(),nums.end(),target); // O(logn)
        auto ub = upper_bound(nums.begin(),nums.end(),target); // O(logn)

        int LB = lb - nums.begin();
        int UB = ub - nums.begin();

        for(int i=LB;i<UB;i++) ans.push_back(i);

        return ans;
    }
};