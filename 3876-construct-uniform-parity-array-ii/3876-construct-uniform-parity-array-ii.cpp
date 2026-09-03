class Solution {
public:
    bool uniformArray(vector<int>& n) {

        int minEle = *min_element(n.begin(),n.end());

        if(minEle % 2 == 1) return true;

        for(int ele:n){
            if(ele%2 == 1) return false;
        }
        
        return true;
    }
};