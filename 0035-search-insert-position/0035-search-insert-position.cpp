class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {

       int low = 0;
       int high = nums.size()-1;
       int ans = 0;

       while(low <= high){
            int mid = (low + high)/2;

            if(nums[mid] <= target){
                if(nums[mid] == target) return mid;
                low = mid + 1;
            }
            else{
                high = mid-1;
            }
       }
       return low;
    }
};