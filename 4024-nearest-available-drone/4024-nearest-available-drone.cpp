class Solution {
public:
    int nearestDrone(vector<vector<int>>& drones, vector<int>& target) {
        
        int index = -1;
        int diff = INT_MAX;
        
        for(int i=0;i<drones.size();i++){
            int targetx = target[0];
            int targety = target[1];

            int dronesx = drones[i][0];
            int dronesy = drones[i][1];

            int range2 = drones[i][2];

            int range1 = abs(dronesx - targetx) + abs(dronesy-targety);
            
            if(range1 <= range2) {
                if(range1 < diff) {
                    diff = range1;
                    index = i;
                }
            }

        }
        return index;
    }
};