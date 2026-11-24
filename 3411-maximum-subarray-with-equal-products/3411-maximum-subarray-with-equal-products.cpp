class Solution {
public:
    int maxLength(vector<int>& nums) {
        
        int p = 1;
        int g = 1;
        int l = 1; 

        int n = nums.size();

        int maxLen = INT_MIN;

        for(int i=0;i<n;i++){
            
            long long p = 1;
            long long g = 0;
            long long l = 1;

            for(int j=i;j<n;j++){
                
                p = p * nums[j];
                g = gcd(g,nums[j]);
                l = lcm(l,nums[j]);

                if(p == g * l){
                    maxLen = max(maxLen,j-i+1);
                }
                if(p > 36288900) break;
            }
            g = 1;
        }
        return maxLen;
    }
};