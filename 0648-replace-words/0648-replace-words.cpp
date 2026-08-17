class Solution {
public:

    string find_root(string &word, unordered_set<string> &set){

        for(int i=1;i<word.size();i++){
            string root = word.substr(0,i);
            if(set.count(root)){
                return root;
            }
        }
        return word;
    }

    string replaceWords(vector<string>& d, string sentence) {

        unordered_set<string> st(d.begin(),d.end());

        stringstream ss(sentence);
        string word;

        string res;

        while(getline(ss,word,' ')){
            res += find_root(word,st) +" ";
        }
        res.pop_back();
        return res;
    }
};