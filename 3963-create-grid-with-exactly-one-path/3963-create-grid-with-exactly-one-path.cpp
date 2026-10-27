class Solution {
public:
    vector<string> createGrid(int m, int n) {

        vector<string>ans(m,"#");

        string temp = "";

        for(int i=0;i<m;i++){
            temp = "";
            for(int j=0;j<n;j++){
                if(i == 0 || j == n-1){
                    temp += '.';
                }else{
                    temp += '#';
                }
            }
            ans[i] = temp;
        }

        return ans;
    }
};