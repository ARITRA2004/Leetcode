class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();

        unordered_map<int,int>mpp;

        for(int i=0;i<n;i++){
            mpp[nums[i]]++;
        }

        if(k == n){
            return *max_element(nums.begin(),nums.end());
        }

        if(k == 1){
            int max_val = -1;

            for(int i=0;i<n;i++){
                if(mpp[nums[i]] == 1 && nums[i] > max_val){
                    max_val = nums[i];
                }
            }

            return max_val;
        }

        n = n-1;

        if(nums[0] == nums[n]){
            return -1;
        }

        if(mpp[nums[0]] == 1 && mpp[nums[n]] == 1){
            return max(nums[0],nums[n]);
        }

        if(mpp[nums[0]] == 1 && mpp[nums[n]] > 1){
            return nums[0];
        }
        if(mpp[nums[n]] == 1  && mpp[nums[0]] > 1){
            return nums[n];
        }

        return -1;
    }
};