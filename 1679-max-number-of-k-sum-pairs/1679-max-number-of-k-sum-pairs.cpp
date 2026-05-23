class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int n = nums.size();
        int right = n-1;
        int left = 0;

        int operations = 0;
        sort(nums.begin(),nums.end());

        while(left<right){
            if(nums[left] + nums[right] > k){
                right--;
            }
            else if(nums[left] + nums[right] < k){
                left++;
            }
            else{
                operations++;
                left++;
                right--;
            }
        }
        return operations;
    }
};