class Solution {
public:

    bool is_valid(vector<int> &freq){
        int common = 0;

        for(int i=0;i<26;i++){
            if(freq[i] == 0) continue;
            else if(common == 0){
                common = freq[i];
            }
            else if(freq[i]!=common) return false;
        }
        return true;
    }

    int longestBalanced(string s) {

        int n = s.size();
        int len = 1;

        for(int i=0;i<n;i++){
            vector<int>freq(26,0);

            for(int j=i;j<n;j++){

                freq[s[j]-'a']++;

                if(is_valid(freq)){
                    len = max(len,j-i+1);
                }
            }
        }

        return len;
    }
};