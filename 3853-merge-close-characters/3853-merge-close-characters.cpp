class Solution {
public:
    
    string mergeCharacters(string s, int k) {

        int n = s.size();
        string result;

        vector<int>l(26,-1);

        for(int i=0;i<n;i++){

            char c = s[i];

            if(l[c-'a'] != -1 && result.length()-l[c-'a'] <= k) continue;
            result.push_back(c);
            l[c-'a'] = result.length()-1;
        }

        return result;
    }
};