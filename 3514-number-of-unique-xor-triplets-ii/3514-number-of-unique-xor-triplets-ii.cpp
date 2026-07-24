class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();
        int maxi = *max_element(nums.begin(),nums.end());
        
        unordered_set<int>pairs;

        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                pairs.insert(nums[i] ^ nums[j]);
            }
        }

        int count = 0;
        unordered_set<int>trip;

        for(int ele:nums){
            for(int x:pairs){
                int res = ele^x;
                trip.insert(res);
            }
        }

        return trip.size();
    }
};