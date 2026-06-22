class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char,int>mpp;

        for(char c:text){
            if(c == 'b' || c == 'a' || c == 'l' || c == 'o' || c == 'n'){
                mpp[c]++;
            }
        }

        // b-> 1, a -> 1, l -> 2, o -> 2, n -> 1 -> 7
        // b -> 6, a -> 1, l -> 2, o -> 2, n-> 3 -> 14

        int min_freq = INT_MAX;

        for(char ch:"balon!"){
            if(ch == '!') break;
            if(ch == 'l' || ch == 'o'){
                min_freq = min(min_freq,mpp[ch]/2);
            }else{
                min_freq = min(min_freq,mpp[ch]);
            }
            cout << "min_freq : " << ch << min_freq << endl;
        }
        // b -> 1 , a -> 1, l -> 2, o -> 2, n -> 1
        // b -> 1, a -> 1, l -> 1, o -> 1, n -> 1 , min_freq = 1
        return min_freq;

    }
};