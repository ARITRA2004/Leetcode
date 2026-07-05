class Solution {
public:

    int digit_range(int num){
        int max_num = 0;
        int min_num = INT_MAX;

        while(num > 0){
            int rem = num % 10;
            max_num = max(max_num,rem);
            min_num = min(min_num,rem);

            num /= 10;
        }
        return max_num - min_num;
    }

    int maxDigitRange(vector<int>& nums) {
        unordered_map<int,vector<int>>mpp;

        int max_digit_range = 0;

        for(int i=0;i<nums.size();i++){
            int digit_r = digit_range(nums[i]);
            max_digit_range = max(max_digit_range,digit_r);
            mpp[digit_r].push_back(nums[i]);
        }

        int sum = 0;

        for(auto value:mpp[max_digit_range]){
            sum = sum + value;
        }
        return sum;
    }
};