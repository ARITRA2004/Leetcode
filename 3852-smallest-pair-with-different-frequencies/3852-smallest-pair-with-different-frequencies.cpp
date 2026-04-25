class Solution {
public:
    vector<int> minDistinctFreqPair(vector<int>& nums) {

        if(nums.size() == 1) return {-1,-1};
        if(nums.size() == 2 && nums[0]!=nums[1]) return {-1,-1};

        map<int,int>m;

        for(int ele:nums) m[ele]++;

        if(m.size() == 1) return {-1,-1};

        auto it = m.begin();
        int first_ele = it->first;
        int f_fq = it->second;
        it++;

        for(;it != m.end();it++){
            if(it->second != f_fq){
                return {first_ele,it->first};
            }
        }

        return {-1,-1};
    }
};