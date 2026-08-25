class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {

        unordered_set<int>set(nums.begin(),nums.end());

        int i=1;

        while(true){
            if(set.find(i*k)!=set.end()){
                i++;
            }else{
                return i*k;
            }
        }

        return 0;
    }
};