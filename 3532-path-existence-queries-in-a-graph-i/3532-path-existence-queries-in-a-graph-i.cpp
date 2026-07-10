class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {

        vector<int>components(n,0);

        components[0] = 0;
        for(int i=1;i<n;i++){
            if(nums[i] - nums[i-1] <= maxDiff){
                components[i] = components[i-1];
            }
            else{
                components[i] = components[i-1] + 1;
            }
        }

        vector<bool>ans;

        for(auto &it:queries){
            ans.push_back(components[it[0]] == components[it[1]]);
        }

        return ans;
    }
};