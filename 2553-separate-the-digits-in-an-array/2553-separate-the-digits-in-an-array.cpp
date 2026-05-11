class Solution {
public:

    void seperate_Digits(int num,vector<int>&ans){
        vector<int>temp;
        while(num > 0){
            int unit = num%10;
            temp.push_back(unit);
            num = num/10;
        }
        reverse(temp.begin(),temp.end());
        
        for(int num:temp) ans.push_back(num);
    }

    vector<int> separateDigits(vector<int>& nums) {

        vector<int>ans;

        for(int num:nums){
            seperate_Digits(num,ans);
        }
        return ans;
    }
};