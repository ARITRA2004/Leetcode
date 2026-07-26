class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int left = 0;
        int right = 0;

        int maxi = 0;
        int z = 0;

        while(right < n){
            if(nums[right] == 0) z++;

            while(z > k){
                if(nums[left] == 0){
                    z--;
                }
                left++;
            }
            right++;

            maxi = max(maxi, right-left);
        }
        return maxi;
    }
};