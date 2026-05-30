class Solution {
public:

    int upper_bound(vector<char> l, int t){
        int low = 0;
        int high = l.size()-1;
        int ans = 0;

        while(low<=high){
            int mid = (low + high)/2;

            if(l[mid] > t){
                ans = mid;
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        if(ans == 0) return 0;
        return ans;
    }

    char nextGreatestLetter(vector<char>& letters, char target) {
        int index = upper_bound(letters,target);
        return letters[index];
    }
};