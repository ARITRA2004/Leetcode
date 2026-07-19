class Solution {
public:
    string smallestSubsequence(string s) {
        string res = "";

        vector<int>last_index(26,-1);

        for(int i=0;i<s.size();i++){
            last_index[s[i]-'a'] = i;
        }

        stack<char>st;
        vector<bool>vis(26,false);

        for(int i=0;i<s.size();i++){
            if(vis[s[i] - 'a']) continue;

            while(!st.empty() && st.top() > s[i]){
                if(last_index[st.top() - 'a'] > i){
                    vis[st.top()-'a'] = false;
                    st.pop();
                }
                else break;
            }
            st.push(s[i]);
            vis[s[i]-'a'] = true;
        }

        while(!st.empty()){
            res += st.top();
            st.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};