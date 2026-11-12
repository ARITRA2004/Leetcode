class Solution {
public:
    vector<vector<string>> findMismatchedSegments(string s1, string s2) {
        
        vector<vector<string>> ans;

        int n = s1.size();

        if(s1 == s2) return ans;

        string str1;
        string str2;
        
        for(int i=0;i<n;i++){

            if(s1[i] == s2[i]){
                
                if(!str1.empty() && !str2.empty()) {
                    
                    ans.push_back({str1,str2});                    
                }
                str1 = "";
                str2 = "";
                continue;
            }

            str1 += s1[i];
            str2 += s2[i];
        }

        if(!str1.empty() && !str2.empty()){
            ans.push_back({str1,str2});
        }
        
        return ans;
    }

};