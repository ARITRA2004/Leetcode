class Solution {
public:

    long sum_mul(int n){
        int tmep = n;

        long res = 0;
        long mul = 1;
        int sum = 0;

        while(n > 0){

            int rem = n%10;
            sum = sum + rem;
            mul = mul * rem;

            n = n/10;
        }

        res = mul + sum;
        return res;
    }

    bool checkDivisibility(int n) {
        if(n % sum_mul(n) == 0) return true;
        return false;
    }
};