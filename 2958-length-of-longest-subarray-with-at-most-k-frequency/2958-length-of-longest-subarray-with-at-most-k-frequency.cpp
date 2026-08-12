class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int left = 0;
        int right = 0;
        int max_len = 0;

        unordered_map<int,int>freq;

        while(right < nums.size()){
            freq[nums[right]]++;
            while(freq[nums[right]] > k){
                freq[nums[left]]--;
                left++;
            }
            max_len = max(max_len,right-left+1);
            right++;
        }
        return max_len;
    }
};