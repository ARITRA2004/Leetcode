class Solution {
public:

    int digit_product(int n){
        int ans = 1;
        int temp = n;

        while(temp > 0){
            int rem = temp % 10;
            ans = ans * rem;
            temp = temp/10;
        }
        return ans;
    }

    int smallestNumber(int n, int t) {
        int temp = n;
        int num_after_product = digit_product(temp);

        while(true){
            int product = digit_product(temp);
            if(product % t == 0){
                return temp;
            }
            temp++;
        }

        return temp;
    }
};