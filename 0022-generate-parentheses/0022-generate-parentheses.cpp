class Solution {
public:

    void solve(int idx, string s, int open, int close, vector<string>&res, int n){

        if(open > n) return;

        if(open + close == 2*n && open == close){
            res.push_back(s);
            return;
        }

        solve(idx + 1, s+'(', open + 1, close, res,n);

        if(open > close){
            solve(idx + 1, s + ')', open, close + 1, res, n);
        }

        return;
    }

    vector<string> generateParenthesis(int n) {
        vector<string>res;

        solve(0,"",0,0,res,n);

        return res;
    }
};