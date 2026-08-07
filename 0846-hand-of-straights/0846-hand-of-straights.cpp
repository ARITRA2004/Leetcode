class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if(hand.size() % groupSize != 0) return false;
        // 1->10000
        // 2->2
        // 3->2
        // 4->1
        // [1,2,3],[2,3,4],[6,7,8]

        unordered_map<int,int>mpp;

        for(int ele:hand) mpp[ele]++;

        for(int card:hand){
            int start_card = card;
            while(mpp[start_card-1]){
                start_card--;
            }

            while(start_card <= card){
                while(mpp[start_card]){
                    for(int next_card = start_card; next_card < start_card + groupSize; next_card++){
                        if(!mpp[next_card]){
                            return false;
                        }
                        mpp[next_card]--;
                    }
                }
                 start_card++;
            }
        }

        return true;

    }
};