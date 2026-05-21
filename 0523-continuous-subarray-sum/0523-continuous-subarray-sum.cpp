class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int>mpp;
        int prefixSum = 0;
        mpp[0] = -1;

        for(int i=0;i<n;i++){
            prefixSum += nums[i];
            int rem = prefixSum%k;
            if(mpp.find(rem)!=mpp.end()){
                int prv_index = mpp[rem];
                int pres_index = i;
                if(abs(pres_index - prv_index) >= 2) return true;
            }
            else mpp[rem] = i;
        }
        return false;
    }
};