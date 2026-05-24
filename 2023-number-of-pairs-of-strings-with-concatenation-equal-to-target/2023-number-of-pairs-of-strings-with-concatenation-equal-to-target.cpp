class Solution {
public:
    int numOfPairs(vector<string>& nums, string target) {
        unordered_map<string,int>mpp;

        for(auto ele:nums){
            mpp[ele]++;
        }
        int count = 0;
        for(string ele:nums){
            if(target.find(ele) == 0){
                string rem = target.substr(ele.size());
                if(mpp.find(rem)!=mpp.end()){
                    count = count + mpp[rem];
                    if(ele == rem) count--;
                }
            }
        }
        return count;
    }
};