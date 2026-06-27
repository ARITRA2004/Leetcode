class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>set;
        int longest_count = 1;

        if(nums.size()==0) return 0;

        for(auto ele:nums){
            set.insert(ele);
        }

        for(auto ele:set){
            if(set.find(ele-1) == set.end()){
                int x = ele;
                int count = 1;
                while(set.find(x+1)!=set.end()){
                    x = x+1;
                    count++;
                }
                longest_count = max(longest_count,count);
            }
        }
        return longest_count;
    }
};