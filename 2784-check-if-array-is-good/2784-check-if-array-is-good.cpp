class Solution {
public:

    int Base(vector<int>&n){
        int maxi = n[0];
        for(int e:n){
            if(maxi < e) maxi = e;
        }
        return maxi;
    }

    bool isGood(vector<int>& nums) {
        unordered_map<int,int>mpp;
        int base = Base(nums);
        // sort(nums.begin(),nums.end());

        int n = nums.size();
        for(int e:nums){
            mpp[e]++;
        }

        if(nums.size() == 2){
            if(nums[0] == 1 && nums[1] == 1) return true;
            return false;
        }
        if(nums.size() == 1) return false;

        for(int i=1;i<=base-1;i++){
            if(mpp[i] == 1) continue;
            return false;
        }
        if(mpp[base] == 2) return true;
        return false;
    }
};