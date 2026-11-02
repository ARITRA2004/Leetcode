class Solution {
public:
    int minMoves2(vector<int>& arr) {

        int n = arr.size();
        nth_element(arr.begin(),arr.begin() + n/2, arr.end());

        int mid = arr[n/2];

        int min_diff = 0;
    
        for(int ele:arr){
            min_diff += abs(mid - ele);
        }

        return min_diff;
    }
};