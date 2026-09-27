class Solution {
public:
    bool canTransform(vector<int>& source, vector<int>& target) {

        long long x = 0;
        for(int ele:source){
            x += ele;
        }

        long long y = 0;
        for(int ele:target){
            y += ele;
        }

        if(x == y) return true;
        return false;
    }
};