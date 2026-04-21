class Solution {
public:

    bool isValid(string w,string p){

        unordered_map<char,int>res;
        unordered_map<char,int>rev_mpp;

        for(int i=0;i<p.size();i++){

            if(res.find(p[i])!=res.end()){

                char prv_value = res[p[i]];
                char new_value = w[i];
                if(prv_value != new_value) return false;
            }
            if(rev_mpp.find(w[i])!=rev_mpp.end()){
                char prv_value = rev_mpp[w[i]];
                char new_val = p[i];
                if(prv_value != new_val) return false;
            }
            res[p[i]] = w[i];
            rev_mpp[w[i]] = p[i];
        }
        return true;
    }
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {

        unordered_map<char,int>res;
        vector<string>str;

        int n = words.size();

        for(int i=0;i<n;i++){
            string w = words[i];

            if(isValid(w,pattern)){
                str.push_back(w);
            }
        }
        return str;
    }
};