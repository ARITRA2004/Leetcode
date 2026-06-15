class Solution {
public:
    int getLength(vector<int>& nums) {
        int max_len = 1;
        int n = nums.size();

        for(int i = 0; i < n;i++){
            unordered_map<int,int>freq;
            unordered_map<int,int>countDistinct;

            for(int j = i;j<n;j++){
                int val = nums[j];
                int oldFreq = freq[val];
                int newFreq = oldFreq + 1;

                freq[val] = newFreq;

                if(oldFreq > 0){
                    countDistinct[oldFreq]--;
                    if(countDistinct[oldFreq] == 0){
                        countDistinct.erase(oldFreq);
                    }
                }

                countDistinct[newFreq]++;

                bool isvalid = false;
                if(freq.size() == 1) isvalid = true;
                else if(countDistinct.size() == 2){
                    int keys[2];
                    int idx = 0;

                    for(auto &p : countDistinct){
                        keys[idx++] = p.first;
                    }

                    int a = min(keys[0],keys[1]);
                    int b = max(keys[0],keys[1]);
                    if (b == 2 * a) {
                        isvalid = true;
                    }
                }
                if(isvalid){
                    int len = j - i +1;
                    max_len = max(max_len,len);
                }
            }
        }
        return max_len;
    }

};