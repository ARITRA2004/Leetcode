class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {

        int n = capacity.size();

        vector<int>diff(n);

        for(int i=0;i<n;i++){
            diff[i] = capacity[i] - rocks[i];
        }

        sort(diff.begin(),diff.end());

        for(int i=0;i<n;i++){
            if(diff[i] == 0) continue;
            if(diff[i] < additionalRocks && additionalRocks > 0){
                int rem = additionalRocks - diff[i];
                additionalRocks = rem;
                diff[i] = 0;
            }else if(diff[i] == additionalRocks){
                diff[i] = 0;
                break;
            }
            else{
                break;
            }
        }

        int count = 0;

        for(int ele:diff){
            if(ele == 0) count++;
        }
        return count;
    }
};