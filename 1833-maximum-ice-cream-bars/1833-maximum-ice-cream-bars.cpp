class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int n = costs.size();
        sort(costs.begin(),costs.end());

        // 1 1 2 3 4
        // 1 1 2 3 5 6
        int c = 0;
        int count = 0;
        
        if(costs[0] > coins) return 0;
        int i=0;
        for(i=0;i<n;i++){
            if(c <= coins){
                if(c == coins) break;
                c += costs[i];
                count++;   
            }else{
                count = count - 1;
                break;
            }
            cout << count;  // 2 3 3 5 6 6 6 7 9 10
            // 1 2 4 5 8
        }
        if(c > coins && i == n) return count-1;
        return count;
    }
};