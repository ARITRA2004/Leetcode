class Solution {
public:

    int minFreq(unordered_map<char,int>& f){
        int mini = INT_MAX;

        for(auto it:f){
            mini = min(mini,it.second);
        }

        return mini;
    }

    vector<string> findRepeatedDnaSequences(string s) {

        int n = s.size();
        vector<string> ans;
        unordered_map<string, int> freq;

        for (int i = 0; i + 10 <= n; i++) {

            string sub = s.substr(i, 10);
            freq[sub]++;
            if (freq[sub] == 2) {
                ans.push_back(sub);
            }
        }

        return ans;
    }
};