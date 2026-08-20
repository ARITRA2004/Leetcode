class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {

        int n = nums.size();

        bool chance = false;

        vector<int>a1;
        vector<int>a2;

        a1.push_back(nums[0]);
        a2.push_back(nums[1]);

        for(int i=2;i<n;i++){
            if(a1.back() > a2.back()){
                a1.push_back(nums[i]);
            }else{
                a2.push_back(nums[i]);
            }
        }

        for(auto it:a2){
            a1.push_back(it);
        }

        return a1;
    }
};

auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();