class Solution {
public:
    int minInsertions(string s) {

        int open = 0;
        int result = 0;

        int i = 0;
        
        while(i < s.size()){
            if(s[i] == '('){
                open++;
                i++;
            }else{
                if(open > 0){
                    open--;
                }else{
                    result++;
                }

                if(i+1 < s.size() && s[i+1] == ')'){
                    i = i + 2;
                }else{
                    result++;
                    i++;
                }
            }
        }

        return result + open * 2;
    }
};