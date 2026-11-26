class Solution {
public:
    bool canAliceWin(int n) {

        if(n < 10) return false;
        if(n == 10) return true;

        int i;
        int temp = n;

        for(i=10;i>=3;i--){
            if(n >= i) n = n - i;
            else{
                if(i % 2 == 0) return false;
                return true;
            }
        }
        return false;
    }
};