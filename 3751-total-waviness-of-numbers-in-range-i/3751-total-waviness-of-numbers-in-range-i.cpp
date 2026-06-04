class Solution {
public:

    int isPeakorNot(int n){
        int org = n;
        vector<int>v;
        int count = 0;
        
        while(n > 0){
            int rem = n%10;
            v.push_back(rem);
            n = n/10;
        }
        reverse(v.begin(),v.end());

        for(int i=1;i<v.size()-1;i++){
            if((v[i] > v[i-1]) && v[i]>v[i+1]) count++;
            else if((v[i] < v[i-1]) && v[i] < v[i+1]) count++;
            else continue;
        }

        return count;
    }
    
    int totalWaviness(int num1, int num2) {        
        int res=0;
        
        for(int i=num1;i<=num2;i++){
            if(i < 101) continue;
            if(isPeakorNot(i)){
                res += isPeakorNot(i);
            }
        }
        return res;
    }
};