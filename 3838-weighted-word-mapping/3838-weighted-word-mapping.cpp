class Solution {
public:

    int sum(string s,vector<int>&weights){
        int res = 0;
        for(int ch:s){
            res += weights[ch-97];
        }
        cout <<"res: "<< res%26 << endl;
        return res%26;

    }

    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string ans = "";

        for(auto s:words){
            int val = sum(s,weights);
            ans.push_back('a' + 25-val);
        }
        return ans;
    }
};