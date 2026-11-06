class Solution {
public:

    int get_large(int num){
        
        vector<int>freq(10,0);

        int temp = num;

        while(temp > 0){
            freq[temp%10]++;
            temp = temp/10;
        }

        int greatest_num = 0;

        for(int i=9;i>=0;i--){
           while(freq[i] > 0){
               greatest_num = greatest_num * 10 + i;
               freq[i]--;
           }
        }

        return greatest_num;
    }
    
    long long maximizeSum(vector<int>& nums, int k) {
        
        vector<long long>gain;

        long long total_sum = 0;
        
        for(int ele:nums){ 
            
            int n = get_large(ele);
            
            total_sum += ele;
            
            int diff = n - ele;
            
            gain.push_back(diff);
        }

        sort(gain.begin(),gain.end(),greater<>());

        long long ans = total_sum;
        
        for(int i=0;i<k;i++){
            ans += gain[i];
        }

        return ans;
    }
};