class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int prefix_sum = nums[0];

        int n = nums.size();

        for(int i=1;i<n;i++){
            if(nums[i] == nums[i-1]+1){
                prefix_sum = prefix_sum + nums[i];
            }else{
                break;
            }
        }

        unordered_set<int>s(nums.begin(),nums.end());

        int ans = 0;
        cout << "prefix: " << prefix_sum << endl;

        int x = prefix_sum;

        while(true){
            if(s.count(x) == 0){
                return x;
            }
            x++;
        }

        return ans;
    }
};