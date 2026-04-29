class Solution {
public:
    int lengthOfLastWord(string s) {
        int len = 0;

        int n = s.size();

        for(int i=n-1;i>=0;i--){

            if(s[i] == ' ' && len == 0) continue;
            if(s[i] == ' ' && len!=0) break;
            
            len++;
        }
        return len;
    }
};