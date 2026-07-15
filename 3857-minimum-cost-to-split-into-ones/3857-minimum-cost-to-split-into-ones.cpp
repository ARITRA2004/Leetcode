class Solution {
public:
    int minCost(int n) {
        int dp[501];
        //n -> 1+ b;
        // n = n-1;

        int a = 1;
        int b = n-1;
        dp[n] = a * b;

        for(int i=n-1;i>=1;i--){
            b = i-1;
            dp[i] = dp[i+1] + a*b;
        }
        return dp[1];
    }
};