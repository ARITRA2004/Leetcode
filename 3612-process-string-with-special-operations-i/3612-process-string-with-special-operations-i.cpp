class Solution {
public:
    string processStr(string s) {
        string res = "";

        for(int i=0;i<s.size();i++){
            if(s[i] == '*'){
                if(!res.empty()) res.pop_back();
            }
            if(s[i] == '#'){
                res = res + res;
            }
            if(s[i] == '%'){
                reverse(res.begin(),res.end());
            }
            if(s[i] >= 'a' && s[i] <= 'z') res = res + s[i];
        }
        return res;
    }
};