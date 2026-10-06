class Solution {
public:
    int minAddToMakeValid(string s) {

        stack<char>st;

        int to_be_balanced = 0;

        for(char ch:s){
            if(ch == '('){
                st.push(ch);
                to_be_balanced++;
            }
            else{
                if(st.empty()){
                    to_be_balanced++;
                }
                else{
                    if(st.top() == '('){
                        st.pop();
                        to_be_balanced--;
                    }
                }
            }   
        }
        return to_be_balanced;
    }
};