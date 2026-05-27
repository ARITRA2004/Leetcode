class Solution {
public:

    int lastIndexofChar(char c, string &w){
        int n = w.size();
        int ans = -1;

        for(int i=0;i<n;i++){
            if(w[i] == c) ans = i;
        }
        return ans;
    }

    int numberOfSpecialChars(string word) {

        int count = 0;
        int n = word.size();

        for(char c = 'a'; c <= 'z';c++){
            int i = lastIndexofChar(c,word);
            int j = word.find(toupper(c));

            if(i!=-1 && j!= string::npos && i<j) count++;
        }

        return count;
    }
};