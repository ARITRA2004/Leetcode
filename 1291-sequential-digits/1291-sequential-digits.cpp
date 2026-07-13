class Solution {
public:

    vector<int> generateNumbers(int low, int high){
        vector<int>ans;

        for(int start=1;start<=9;start++){
            long long num = start;
            int next_digit = start + 1;

            while(next_digit <= 9){
                num = num * 10 + next_digit;
                if(num >= low && num <= high){
                    ans.push_back(num);
                }
                next_digit++;
            }

        }
        sort(ans.begin(),ans.end());
        return ans;
    }

    vector<int> sequentialDigits(int low, int high) {
        return generateNumbers(low,high);
    }
};