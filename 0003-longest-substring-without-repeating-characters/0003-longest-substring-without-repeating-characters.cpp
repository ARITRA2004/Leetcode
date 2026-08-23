class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        int n = s.size();
        unordered_map<char,int>mpp;

        int maxLen = 0;
        int left = 0;
        int right = 0;

        while(right < n){
    
            if(mpp.find(s[right]) != mpp.end()){
                left = max(left,mpp[s[right]] + 1);
            }

            mpp[s[right]] = right;

            maxLen = max(maxLen, right - left + 1);
            right++;
        }

        return maxLen;
    }
};