class Solution {
public:
    vector<string> commonChars(vector<string>& words) {

        unordered_map<char,int>mpp1;

        for(char i = 'a'; i<='z';i++){
            mpp1[i] = 10000;
        }

        for(auto word:words){

            unordered_map<char,int>mpp2;

            for(auto ch:word){
                mpp2[ch]++;
            }

            for(char i = 'a'; i<= 'z';i++){
                    mpp1[i] = min(mpp1[i],mpp2[i]);
            }
        }

        vector<string>ans;

        for(char ch='a'; ch <= 'z'; ch++){
            while(mpp1[ch] > 0){
                ans.push_back(string(1,ch));
                mpp1[ch]--;
            }
        }

        return ans;
    }
};