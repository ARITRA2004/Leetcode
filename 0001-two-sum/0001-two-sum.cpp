class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> mpp;

        for(int i=0;i<nums.size();i++){
            int num = nums[i];
            int moreNeed = target - num;
            if(mpp.find(moreNeed)!=mpp.end()){
                return{mpp[moreNeed],i};
            }
            mpp[num] = i;
        }
        return{};
    }
};