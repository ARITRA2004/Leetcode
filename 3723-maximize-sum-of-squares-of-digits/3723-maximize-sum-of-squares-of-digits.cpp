class Solution {
public:
    string maxSumOfSquares(int num, int sum) {

        string s = "";

        if(num * 9 < sum){
            return s;
        }

        if(num == 1){
            return to_string(sum);
        }

        if(sum <= 9){
            return to_string(sum) + s.append(num-1,'0');
        }

        int no_of_nines = sum / 9;
        int rem = sum % 9;

        for(int i=1;i<=no_of_nines;i++){
            s += '9';
        }

        if(rem != 0){
            s += (rem + '0');
        }

        if(s.size() != num){
            int rem_size = num - s.size();
            s.append(rem_size,'0');
        }

        return s;
    }
};