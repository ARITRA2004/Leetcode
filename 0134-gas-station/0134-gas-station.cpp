class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {

        int total_gas = 0;
        int total_cost = 0;

        for(int val:gas){
            total_gas += val;
        }

        for(int ele:cost){
            total_cost += ele;
        }

        if(total_gas < total_cost){
            return -1;
        }

        int start = 0;
        int currgas = 0;

        for(int i=0;i<gas.size();i++){
            currgas += gas[i] - cost[i];

            if(currgas < 0){
                start = i + 1;
                currgas = 0;
            }
        }

        return start;
    }
};