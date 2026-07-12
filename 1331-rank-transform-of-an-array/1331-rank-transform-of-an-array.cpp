class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {

        if(arr.size() == 0) return {};

        int mx = *max_element(arr.begin(),arr.end());
        vector<int>ans = arr;

        unordered_map<int,int>mpp;
        sort(ans.begin(),ans.end());
        int n = arr.size();

        mpp[ans[0]] = 1;

        for(int i=1;i<n;i++){
            if(mpp.find(ans[i]) == mpp.end()){
                mpp[ans[i]] = mpp[ans[i-1]] + 1;
            }
        }

        for(int i=0;i<n;i++){
            ans[i] = mpp[arr[i]];
        }
        return ans;
    }
};