class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        int cnt_o = 0;
        
        int c = 1;
        int i = 1;

        while(c <= n){
            cnt_o += i;
            i = i+2;
            c++;    
        }

        c = 1;
        i = 2;
        int cnt_e = 0;

        while(c <= n){
            cnt_e += i;
            i = i+2;
            c++;
        }

        int res = __gcd(cnt_o,cnt_e);

        return res;
    }
};