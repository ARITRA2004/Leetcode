class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {


        for(int i = 0; i< nums.size();i++){
            if(nums[i] < 0){
                nums[i] = -1*nums[i];
            }
        }

        sort(nums.begin(),nums.end(),greater<int>());

        long long ans = 0;

        int i=0;
        int j = nums.size()-1;

        while(i <= j){

            int leftEle = nums[i];
            int rightEle = nums[j];

            long long res = 0;

            if( i == j){
                res = nums[i]*nums[i];    
            }else{
                res = (nums[i]*nums[i]) - (nums[j]*nums[j]);
            }

            ans += res;

            cout << ans << endl;
            i++;j--;
        }

        return ans;
    }
};