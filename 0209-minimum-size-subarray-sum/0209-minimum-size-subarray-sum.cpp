class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int min_size = INT_MAX;

        int n = nums.size();
        int sum = 0;
        int left = 0;

        for(int right=0;right<n;right++){
            sum += nums[right];
            
            while(sum >= target){
                min_size = min(min_size,right - left + 1);
                sum -= nums[left];
                left++;
            }
        }
        if(min_size == 0 || min_size == INT_MAX) return 0;
        return min_size;
    }
};