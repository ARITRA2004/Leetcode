class Solution {
public:
    int maxDistance(vector<int>& colors) {

        int maxi = INT_MIN;
        int n = colors.size();

        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int color1 = colors[i];

                if(color1 != colors[j]){
                    int diff = abs(j-i);
                    maxi = max(maxi,diff);
                }
            }
        }
        return maxi;
    }
};