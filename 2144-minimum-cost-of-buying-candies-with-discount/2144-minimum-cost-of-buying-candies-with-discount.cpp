class Solution {
public:
    int minimumCost(vector<int>& cost) {

        if(cost.size() == 1) return cost[0];

        sort(cost.begin(),cost.end(),greater<int>());
        // 9 7 6 5 2 2 1

        int n = cost.size();
        
        int total_cost = 0;
        int i=0;

        while(i<n){
            if(i+1 == n) total_cost += cost[i];
            else{
                total_cost = total_cost + cost[i] + cost[i+1];
            }
            i = i+3;
        }
        return total_cost;
    }
};