class Solution {
public:

    bool check_last_first_is_valid(long long num, int x){

        if(num%10 != x) return false;

        while(num >= 10){
            num = num / 10;
        }
        return (num == x);
    }

    int countValidSubarrays(vector<int>& nums, int x) {
        vector<long long>prefix(nums.size()+1,0);

        int n = nums.size();
        
        for(int i=0;i<n;i++){
            prefix[i+1] = prefix[i] + nums[i];
        }

        int count = 0;

        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                long long sum = prefix[j+1] - prefix[i];
                if(check_last_first_is_valid(sum,x)) count++;
            }
        }
        return count;
    }
};