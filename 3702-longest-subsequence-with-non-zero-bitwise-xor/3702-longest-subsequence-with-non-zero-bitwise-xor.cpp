class Solution {
public:
    int longestSubsequence(vector<int>& nums) {

        int n = nums.size();

        vector<int>prefix_xor(n);
        prefix_xor[0] = nums[0];

        for(int i=1;i<n;i++){
            prefix_xor[i] = prefix_xor[i-1] ^ nums[i];
        }


        int max_len = 0;
        bool all_zeros = true;

        for(int ele:prefix_xor){
            if(ele != 0){
                all_zeros = false;
                break;
            }
        }

        if(all_zeros) return 0;

        if(prefix_xor[n-1] == 0){
            return n-1;
        }
        return n;
    }
};