class Solution {
public:

    int solve(vector<int> &nums, int i, int j){
        
        int n = nums.size();

        unordered_map<int,int>mpp;

        int count = 0;

        for(int k = i; k<=j ;k++){
            
            if(mpp.find(nums[k]) == mpp.end()){
                mpp[nums[k]] = 1;
                count++;
            }
        }

        mpp.clear();
        return count;
    }

    int sumCounts(vector<int>& nums) {
        
        int n = nums.size();

        int res = 0;

        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){

                int cnt = solve(nums,i,j);
                res += cnt * cnt;
            }
        }

        res += 1*n;

        return res;
    }
};