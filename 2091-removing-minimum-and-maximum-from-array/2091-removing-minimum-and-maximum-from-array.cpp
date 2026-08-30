class Solution {
public:
    int minimumDeletions(vector<int>& nums) {

        int mini = *min_element(nums.begin(),nums.end());
        int maxi = *max_element(nums.begin(),nums.end());

        int n = nums.size();

        if(n == 1) return 1;

        int minPos = 0;
        int maxPos = 0;

        int dis1 = 0;
        int dis2 = 0;

        for(int i=0;i<n;i++){
            if(nums[i] == mini){
                minPos = i;
            }
            if(nums[i] == maxi){
                maxPos = i;
            }
        }


        // 1. Remove both from the left
        int left = max(minPos + 1, maxPos + 1);

        // 2. Remove both from the right
        int right = max(n - minPos, n - maxPos);

        // 3. Remove min from left, max from right
        int leftRight = (minPos + 1) + (n - maxPos);

        // 4. Remove max from left, min from right
        int rightLeft = (maxPos + 1) + (n - minPos);

        return min({left, right, leftRight, rightLeft});
    }
};