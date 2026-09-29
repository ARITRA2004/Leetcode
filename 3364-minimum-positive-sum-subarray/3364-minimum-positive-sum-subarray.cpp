class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {

        int n = nums.size();

        int sum = 0;
        int min_sum = INT_MAX;

        for(int i=0;i<n;i++){
    
            for(int j=i;j<n;j++){

                sum = sum + nums[j];
                
                if(sum > 0 && j-i+1 >= l && j-i+1 <= r){
                    min_sum = min(min_sum,sum);
                }
            }
            sum = 0;
        }
        if(min_sum == INT_MAX) return -1;
        return min_sum;
    }
};