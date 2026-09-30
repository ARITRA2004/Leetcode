class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        
        int n = seq.size();

        stack<pair<char,int>>st;
        vector<int>res;

        st.push({'(',0});
        res.push_back(0);

        for(int i=1;i<n;i++){
            if(seq[i] == '('){
                if(!st.empty()){
                    int value = st.top().second;
                    st.push({'(',value+1});
                    res.push_back((value+1)%2);
                }else{
                    st.push({'(',0});
                    res.push_back(0);
                }
            }
            else if(seq[i] == ')'){
                int value = st.top().second;
                res.push_back(value%2);
                st.pop();
            }
        }

        return res;
    }
};