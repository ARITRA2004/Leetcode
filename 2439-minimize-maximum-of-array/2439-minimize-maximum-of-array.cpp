class Solution {
public:

    bool isPossible(vector<int> nums, int mid){
        vector<long long> arr(nums.begin(), nums.end());
        int n = arr.size();
        for(int i=n-1;i>=1;i--){
            if(arr[i] > mid){
                long long req = arr[i] - mid; // 7-4 -> 3
                arr[i] = arr[i] - req;
                arr[i-1] = arr[i-1]+req;
            }
        }

       return arr[0] <= mid;
    }

    int minimizeArrayValue(vector<int>& nums) {
        int high = *max_element(nums.begin(),nums.end());
        int low = 0;

        while(low <= high){
            int mid = (low+high)/2;

            if(isPossible(nums,mid) == false){
                low = mid+1;
            }else{
                high = mid-1;
            }
        }
        return low;
    }
};