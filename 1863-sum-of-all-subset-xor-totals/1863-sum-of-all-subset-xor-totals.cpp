class Solution {
public:

    int result(vector<int>&arr, int idx, int xorr){
        if(idx == arr.size()){
            return xorr;
        }

        int take = result(arr,idx+1,xorr^arr[idx]);
        int nottake = result(arr,idx+1,xorr);

        return take + nottake;
    }

    int subsetXORSum(vector<int>& nums) {
        int sum = result(nums,0,0);
        return sum;
    }
};