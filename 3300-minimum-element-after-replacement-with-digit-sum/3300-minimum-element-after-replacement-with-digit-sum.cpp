class Solution {
public:

    int sum_of_digit(int ele){
        int sum = 0;
        while(ele > 0){
            int rem = ele%10;
            sum = sum + rem;
            ele /= 10;
        }
        return sum;
    }

    int find_min(vector<int> &nums){
        int mini = nums[0];
        int n = nums.size();

        for(int ele:nums){
            mini = min(mini,ele);
        }
        return mini;
    }

    int minElement(vector<int>& nums) {
        int sum = sum_of_digit(nums[0]);
        int mini = INT_MAX;
        mini = min(mini,sum);
        
        int n = nums.size();

        for(int i=1;i<n;i++){
            sum = sum_of_digit(nums[i]);
            mini = min(mini,sum);
        }
        return mini;
    }
};