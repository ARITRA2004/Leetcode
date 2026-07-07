class Solution {
public:
    long long SUM (int n){
        long long ssum = 0;

        while(n > 0){
            int rem = n % 10;
            ssum += rem;
            n /= 10;
        }
        return ssum;
    }

    long long num(int n){
        long long ans = 0;
        long long place = 1;

        while(n > 0){
            int rem = n%10;
            if(rem != 0){
                ans += rem * place;
                place = place * 10;
            }
            n /= 10;
        }
        return ans;
    }

    long long sumAndMultiply(int n) {

        int org = n;
        long long res = SUM(n);
        long long num_without_zero = num(org);
        long long ans = 1LL * res * num_without_zero;

        return ans;
    }
};