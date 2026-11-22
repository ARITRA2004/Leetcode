class Solution {
public:
    bool checkString(string s) {

        int n = s.size();
        int a_idx = -1;
        int b_idx = -1;

        for(int i=0;i<n;i++){
            if(s[i] == 'a'){
                a_idx = i;
            }
            if(s[i] == 'b'){
                b_idx = i;
            }

            //main calculation
            if(a_idx > b_idx && a_idx >= 0 && b_idx >= 0){
                return false;
            }
        }

        return true;
    }
};