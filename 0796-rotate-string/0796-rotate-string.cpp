class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s == goal) return true;

        string temp = s;

        for(int i=0;i<s.size();i++){
            rotate(temp.begin(),temp.begin()+1,temp.end());
            if(temp == goal) return true;
        }
        return false;

    }
};