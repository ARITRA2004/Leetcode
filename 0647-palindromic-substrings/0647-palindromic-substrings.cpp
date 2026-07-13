class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        int dp[1000][1000]={0};

        int count_palin = 0;

        // for length 1 substrings
        int i=0;
        while(i<n){
            dp[i][i] = 1;
            count_palin++;
            i++;
        }

        // for length 2 substrings
        i=0;
        while(i<n-1){
            if(s[i] == s[i+1]){
                dp[i][i+1] = 1;
                count_palin++;
            }
            i++;
        }

        // for length 3,4,..... substrings
        int len = 3;
        while(len <= n){
            i = 0;
            while(i < n-len+1){
                int j = i+len-1;
                if(s[i] == s[j] && dp[i+1][j-1] == 1){
                    dp[i][j] = 1;
                    count_palin++;
                }
                i++;
            }
            len++;
        }
        return count_palin;
    }
};