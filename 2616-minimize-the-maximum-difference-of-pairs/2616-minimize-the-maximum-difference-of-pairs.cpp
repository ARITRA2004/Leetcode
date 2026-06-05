class Solution {
public:
    // 1 1 2 3 7 10
    // 1 2 2 4
    bool isPossible(vector<int>&nums, int diff, int p){
        int pairs = 0;
        int last_ele = nums[0];

        for(int i=1;i<nums.size();i++){
            if(nums[i] - nums[i-1] <= diff){
                pairs++;
                i++;
            }
        }
        if (pairs >= p) return true;
        return false;
    }

    int minimizeMax(vector<int>& nums, int p) {

       sort(nums.begin(), nums.end());
       
       int n = nums.size();

       int low = 0;
       int high = nums[n-1] - nums[0];

       while(low <= high){
            int mid = (low+high)/2;

            if(isPossible(nums,mid,p) == true){
                high = mid-1;
            }
            else low = mid+1;
        }
        return low;
    }
};