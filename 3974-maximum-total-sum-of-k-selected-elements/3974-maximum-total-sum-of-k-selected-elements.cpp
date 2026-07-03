class Solution {
public:
    long long maxSum(vector<int>& nums, int k, int mul) {
        sort(nums.begin(),nums.end(),greater<int>());

        long long res = 0;

        for(int i=0;i<k;i++){
            if(mul > 0) {
                res += 1LL * nums[i] * mul;
                mul--;
            }
            else res = res + nums[i];
            cout << res << endl;
        }
        return res;
    }
};