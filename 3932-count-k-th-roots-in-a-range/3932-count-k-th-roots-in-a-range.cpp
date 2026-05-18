class Solution {
public:
    int countKthRoots(int l, int r, int k) {
        int count = 0;
        if(k == 1) return r-l+1;
        
        for(int i=0;i<= pow(r,1.0/k)+1;i++){
            long long res = pow(i,k);
            if(res >= l && res <= r) count++;
        }
        // cout << count;
        return count;
    }
};