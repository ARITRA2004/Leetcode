class Solution {
public:
    string getHint(string secret, string guess) {
        int n = secret.size();

        // count no of bulls
        int cnt_bulls = 0;
        for(int i = 0;i<n;i++){
            if(secret[i] == guess[i]){
                cnt_bulls++;
                secret[i] = '#';
                guess[i] = '#';
            }
        }

        //count no of cows
        unordered_map<char,int>mp1;
        unordered_map<char,int>mp2;

        // insert all the elements of secret 
        for(int i=0;i<n;i++) {
            if(secret[i] != '#') mp1[secret[i]]++;
        }

        //insert all the elements of guess
        for(int i=0;i<n;i++) {
            if(guess[i] != '#') mp2[guess[i]]++;
        }

        int cnt_cows = 0;
        for(auto it:mp1){
            if(mp2.find(it.first)!=mp2.end()){
                cnt_cows = cnt_cows + min(it.second,mp2[it.first]);
            }
        }

        string str = to_string(cnt_bulls) + 'A' + to_string(cnt_cows) + 'B';

        return str;

    }
};