class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int low = 1;
        int high = *max_element(begin(nums),end(nums));

        while(low < high){
            int mid = (low+high)/2;

            int count = 0;
            for(int i=0;i<nums.size();i++){
                if(nums[i] <= mid){
                    count++;
                }
            }

            if(count > mid){
                high = mid;
            }
            else low = mid+1;
        }
        return low;
    }
};