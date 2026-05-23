class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int n = nums.size();
        int operations = 0;

        unordered_map<int,int>mpp;
        
        for(int ele:nums){
            int req = k-ele;
            if(mpp.find(req)!=mpp.end()){
                operations++;
                mpp[req]--;
                if(mpp[req] == 0){
                    mpp.erase(req);
                }
            }else{
                cout << mpp[ele] << endl;
                mpp[ele]++;
            }
        }

        return operations;
    }
};