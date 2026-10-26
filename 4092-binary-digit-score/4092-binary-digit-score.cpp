class Solution {
public:

    int countOnes(int n){
        int cnt = 0;

        while(n){
            n = n & (n-1);
            cnt++;
        }

        return cnt;
    }
    
    int calculateScore(int a, int b) {
        int s1 = countOnes(a);
        int s2 = countOnes(b);

        if(s1 >= s2) return s1*s2;
        return s2/s1;
    }
};