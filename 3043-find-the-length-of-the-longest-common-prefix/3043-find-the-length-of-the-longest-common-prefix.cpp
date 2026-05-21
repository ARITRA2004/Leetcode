class Solution {
public:

    string con_str(int n){
        string temp = to_string(n);
        return temp;
    }

    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {

        unordered_set<string>us;
        
        for(int ele:arr1){
            string temp = "";
            string str = con_str(ele);
            for(char c:str){
                temp += c;
                us.insert(temp);
            }
        }

        int maxiLen = 0;

        for(int ele:arr2){
            string temp = "";
            string str = con_str(ele);
            for(char c:str){
                temp += c;
                if(us.find(temp)!=us.end()){
                    int size = temp.size();
                    maxiLen = max(maxiLen,size);
                }
            }
        }
        return maxiLen;
        
    }
};