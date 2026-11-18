class Solution {
public:
    int minChanges(string s) {

        int count_changes = 0;

        for(int i=0;i<s.size();i = i+2){

            string substr = s.substr(i,2);

            if(substr[0] != substr[1]){
                count_changes++;
            }

        }
        
        return count_changes;
    }
};