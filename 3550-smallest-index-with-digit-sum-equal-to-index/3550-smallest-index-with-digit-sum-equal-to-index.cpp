class Solution {
public:

    int digitSum(int num){
        int res = 0;

        while(num > 0){
            int rem = num%10;
            res = res + rem;
            num /= 10;
        }

        return res;
    }

    int smallestIndex(vector<int>& nums) {

        vector<int>res;

        for(int num:nums){
            int ans = digitSum(num);
            res.push_back(ans);
        }

        for(int i=0;i<nums.size();i++){
            if(res[i] == i){
                return i;
            }
        }

        return -1;
    }
};