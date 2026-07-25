class Solution {
public:

    pair<int,int>max_two_numbers(int n){
        int maxi = -1;
        int mini = -1;

        while(n > 0){
            int last_digit = n%10;
            if(last_digit > maxi && maxi >= mini){
                mini = maxi;
                maxi = last_digit;
            }else if(last_digit > mini){
                mini = last_digit;
            }
            n = n/10;
        }
        return {maxi,mini};
    }

    int maxProduct(int n) {
        auto [maxi,mini] = max_two_numbers(n);
        long long res =  maxi*mini;
        return (int)res;
    }
};