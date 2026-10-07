class Solution {
public:
    int n;
    int maxLen;
    unordered_set<string>st;

    void solve(string &s, int i, string &curr, int count){

        if(count < 0) return;

        // base case
        if(i == n){
            if(count == 0){ // valid
                if(curr.length() > maxLen){
                    maxLen = curr.length();
                    st.clear();
                }
                if(maxLen == curr.length()) {
                    st.insert(curr);
                }
            }
            return;
        }

        // if alphabet is pressent 
        if(s[i] != '(' && s[i] != ')'){

            curr.push_back(s[i]);
            solve(s, i+1, curr, count);

            curr.pop_back();
            return;
        }

        // if only bracket

        curr.push_back(s[i]);

        solve(s,i+1,curr,count + (s[i] == '(' ? 1 : -1));

        curr.pop_back();

        solve(s,i+1,curr,count);
    }

    vector<string> removeInvalidParentheses(string s) {
        
        n = s.size();

        string curr = "";
        st.clear();

        solve(s,0,curr,0);

        return vector<string>(st.begin(),st.end());
    }
};