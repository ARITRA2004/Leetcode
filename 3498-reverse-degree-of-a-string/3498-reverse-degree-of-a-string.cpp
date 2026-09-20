class Solution {
public:
    int reverseDegree(string s) {
        int res = 0;
        int n = s.size();

        for(int i=0;i<n;i++){
            int val = 'z' - s[i] + 1;
            res += val*(i+1);
        }

        return res;
    }
};