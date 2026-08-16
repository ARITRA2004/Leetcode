class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int n = nums.size();

        if(k == 0){

            int ans = 0;

            unordered_map<int,int>mpp;

            for(int ele:nums){
                mpp[ele]++;
            }

            for(auto it:mpp){
                if(it.second >= 2){
                    ans++;
                }
            }
            return ans;
        }

        int ans = 0;

        unordered_set<int>set;

        for(int i=0;i<n;i++){
            set.insert(nums[i]);
        }

        for(int ele:set){
            if(set.count(ele + k)){
                ans++;
            }
        }

        // 1 -> 5
        // n = 5
        // set.size() = 1

        return ans;
    }
};