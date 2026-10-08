class Solution {
public:
    string removeOuterParentheses(string s) {

        string ans = "";

        int open = 0;

        for(int i=0;i<s.size();i++){

            if(s[i] == ')'){

                open--;

                if(open > 0){
                    ans += s[i];
                }
            }

            if(s[i] == '('){

                open++;

                if(open > 1){
                    ans += s[i];
                }
            }
        }

        return ans;
    }
};