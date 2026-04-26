class Solution {
public:
    vector<int> findValidElements(vector<int>& nums) {

        int n = nums.size();
        vector<int>res(n,-1);

        if(n == 1) return {nums[0]};

        // cal max from the left to right
        int maxi=0;

        res[0] = nums[0];
        res[n-1] = nums[n-1];
        maxi = nums[0];

        for(int i=1;i<n;i++){
            if(maxi < nums[i]){
                maxi = nums[i];
                res[i] = nums[i];
            }
        }

        maxi = nums[n-1];

        for(int i=n-2;i>=0;i--){
                if(maxi < nums[i]){
                    maxi = nums[i];
                    res[i] = nums[i];
                }
        
        }

        for(int ele:res) cout << ele << " ";

        vector<int>final_res;

        for(int ele:res){
            if(ele != -1)  final_res.push_back(ele);
        }
        return final_res;
    }
};