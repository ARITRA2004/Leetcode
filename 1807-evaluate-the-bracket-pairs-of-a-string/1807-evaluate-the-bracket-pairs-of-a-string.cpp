class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string,string>mpp; // 10^5

        int n = knowledge.size();

        for(auto &it:knowledge){
            mpp[it[0]] = it[1];
        }

        bool is_bracket = false;
        string res = ""; //10^5

        for(int i = 0;i<s.size();i++){
            if(s[i] == '('){
                int start_index = i;
                is_bracket = true;
                string temp = "";
                while(is_bracket!=false){
                    if(s[i] == ')') is_bracket = false;
                    else i++;
                }
                // extract the (value)
                temp = s.substr(start_index + 1 , i - (start_index + 1));
                if(mpp.find(temp)!=mpp.end()){
                    res.append(mpp[temp]);
                }else{
                    res.push_back('?');
                }
            }
            else{
                res.push_back(s[i]);
            }   
        }
        return res;
    }
};