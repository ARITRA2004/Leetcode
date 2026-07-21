class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int ones= 0;
        for(char ch:s){
            if(ch == '1'){
                ones++;
            }
        }

        s = '1' + s + '1';

        int n = s.size();
        int i = 0;

        int ans = ones;
        int prv_zero = -1;


// 1 000 1
        // skip the first one's 
        while(i < n && s[i] == '1'){
            i++;
        }

        while(i < n){
            
            int count_zero_block1 = 0;

            // now I am considering the first 0 blocks
            while(i < n && s[i] == '0'){
                count_zero_block1++;
                i++;
            }

            if(prv_zero == -1){
                prv_zero = count_zero_block1;
            }

            // now I will skip 1
            while(i < n && s[i] == '1') i++;

            //now I will canculate the 0's after the 1
            int count_zero_after_middle_block_whic_is_one = 0;

            while(i < n){
                if(s[i] == '0'){
                    count_zero_after_middle_block_whic_is_one++;
                }else{
                    break;
                }
                i++;
            }

            if(count_zero_after_middle_block_whic_is_one > 0){
                ans = max(ans,ones + prv_zero + count_zero_after_middle_block_whic_is_one);
            }

            prv_zero = count_zero_after_middle_block_whic_is_one;
        }
        return ans;
    }
};