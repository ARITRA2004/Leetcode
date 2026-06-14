class Solution {
public:
    bool checkGoodInteger(int n) {
        int sq_sum = 0;
        int dig_sum = 0;

        while(n > 0){
            int rem = n%10;
            dig_sum = dig_sum + rem;
            sq_sum = sq_sum + (rem*rem);
            n = n/10;
        }
        return sq_sum - dig_sum >= 50;
    }
};