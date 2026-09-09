class Solution {
public:
    long long countCommas(long long n) {
        if(n < 1000) return 0;
        
        long long count_commas = 0;

        if(n >= 1e3){
            if(n <= 1e6-1) count_commas = 1 + n - 1e3;
            else if(n <= 1e9-1) count_commas = 3 + 2*n - (1e6 + 1e3) - 1;
            else if(n <= 1e12-1) count_commas = 6 + 3*n - 1e9 - 1e6 - 1e3 - 3;
            else if(n <=  1e15 - 1) count_commas = 10 + 4*n - 1e12 - 1e9 - 1e6 - 1e3-6;
        }
        // if(n >= 1e6 && n <= 1e9-1){
        //     count_commas += 2 + n - 1e6;
        // }
        // if(n >= 1e9 && n <= 1e12-1){
        //     count_commas += 3 + n - 1e9;
        // }
        // if(n >= 1e12 && n <=  1e15 - 1){
        //     count_commas += 4 + n - 1e12;
        // }

        if(n == 1e15) count_commas = 10 + 4*n - 1e12 - 1e9 - 1e6 - 1e3 - 6 + 1;

        cout << n << endl;
        return count_commas;
    }
};