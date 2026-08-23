class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        // 10 9 8 7 g
        // 5  6 8 7s

        sort(g.begin(),g.end());

        sort(s.begin(),s.end());

        int cnt = 0;

        int right = 0;
        int left = 0;

        while(left < g.size() && right < s.size()){
            if(g[left] <= s[right]){
                cnt++;
                left = left + 1;
            }
            right++;
        }
        return cnt;
    }
};