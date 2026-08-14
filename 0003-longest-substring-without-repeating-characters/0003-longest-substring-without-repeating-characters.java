class Solution {
    public int lengthOfLongestSubstring(String s) {
        int max_len = 0;

        HashMap<Character,Integer>mpp = new HashMap<>();

        int left = 0;
        int right = 0;

        int n = s.length();

        while(right < n){

            char ch = s.charAt(right);

            if(mpp.containsKey(ch)){
                left = Math.max(left, mpp.get(ch) + 1);
            }
            
            mpp.put(ch,right);

            max_len = Math.max(max_len,right-left+1);
            right++;
        }

        return max_len;
    }
};