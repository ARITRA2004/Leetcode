class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int altitude = 0;
        int n = gain.size();

        int max_altitude = altitude;

        for(int i=0;i<n;i++){
            altitude = altitude + gain[i];
            max_altitude = max(max_altitude,altitude);
        }

        return max_altitude;
    }
};