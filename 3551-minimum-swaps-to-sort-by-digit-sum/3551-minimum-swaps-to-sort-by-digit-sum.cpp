class Solution {
public:

    int getDigitSum(int num){
        int res = 0;

        while(num > 0){
            int rem = num % 10;
            res += rem;

            num /= 10;
        }

        return res;
    }

    int minSwaps(vector<int>& nums) {

        int n = nums.size();

        vector<int>afterSort(nums);

        auto lambda = [this](int num1, int num2){

            int num1DigitSum = getDigitSum(num1);
            int num2DigitSum = getDigitSum(num2);

            if(num1DigitSum != num2DigitSum){
                return num1DigitSum < num2DigitSum;
            }

            return num1 < num2;
        };

        sort(afterSort.begin(), afterSort.end(),lambda);

        unordered_map<int,int>mpp;

        for(int i=0;i<n;i++){
            mpp[nums[i]] = i;
        }

        int swap_cnt = 0;

        for(int i=0;i<n;i++){
            int expected = afterSort[i];
            int currVal = nums[i];

            if(currVal == expected) continue;

            int idx = mpp[expected];

            nums[i] = expected;
            nums[idx] = currVal;

            mpp[expected] = i;
            mpp[currVal] = idx;

            swap_cnt++;
        }

        return swap_cnt;
    }
};