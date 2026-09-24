class Solution {
public:
    int countIntersectingIntervals(vector<vector<int>>& in) {

        int n = in.size();
        int cnt = 0;

        sort(in.begin(),in.end());

        for(int i = 0;i<n-1;i++){

            for(int j = i+1;j < n;j++){

                if(in[i][1] >= in[j][0]){
                    cnt++;
                }
            }
        }

        return cnt;
    }
};