class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {

        bool is_valid = false;

        int count = 0;

        for(int ele1:arr1){

            for(int ele2:arr2){

                if(abs(ele1 - ele2) > d){

                    is_valid = true;

                }else {
                    is_valid = false;
                    break;
                }
            }
            if(is_valid == true){
                count++;
            }
        }
        return count;
    }
};