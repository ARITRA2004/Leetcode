class Solution {
public:
    string rearrangeString(string s, char x, char y) {

        string res = s;

        int swap_idx_y = 0;
        for(int i=0;i<s.size();i++){
            if(s[i] == y){
                swap(res[i],res[swap_idx_y]);
                swap_idx_y++;
            }
        }

        int swap_idx_x = s.size()-1;
        for(int i=s.size()-1;i>=0;i--){
            if(res[i] == x){
                swap(res[i],res[swap_idx_x]);
                swap_idx_x--;
            }
        }

        return res;
    }
};