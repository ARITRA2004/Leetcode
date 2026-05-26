class Solution {
public:
    int numberOfSpecialChars(string word) {
        unordered_set<char>lower,upper;
        int count = 0;

        for(char ch:word){
           if(ch >= 'a' && ch <='z') lower.insert(ch);
           else upper.insert(ch);
        }

        for(char i='a';i<='z';i++){
            if(lower.find(i)!=lower.end() && upper.find(i-32)!=upper.end()){
                count++;
            }
        }
        return count;
    }
};