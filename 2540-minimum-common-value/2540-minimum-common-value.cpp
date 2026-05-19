class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        
        int right = 0;
        int left = 0;

        while(left < nums1.size() && right < nums2.size()){
            if(nums1[left] < nums2[right]) left++;
            else if(nums1[left] > nums2[right]) right++;
            else return nums1[left];
        }
        return -1;
    }
};