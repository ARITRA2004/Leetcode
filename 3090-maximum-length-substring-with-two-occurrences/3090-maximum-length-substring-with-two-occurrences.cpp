class Solution {
public:
    int maximumLengthSubstring(string s) {

        unordered_map<char,int>mpp;
        int n = s.size();

        int left = 0;
        int right = 0;
        
        int len = 0;
        int max_len = 0;

        while(right < n){
            mpp[s[right]]++;

            while(mpp[s[right]] > 2 && left <= right){
                mpp[s[left]]--;
                if(mpp[s[left]] == 0){
                    mpp.erase(s[left]);
                }
                left++;

            }

            max_len = max(max_len,right - left + 1);
            right++;
        }

        return max_len;
    }
};