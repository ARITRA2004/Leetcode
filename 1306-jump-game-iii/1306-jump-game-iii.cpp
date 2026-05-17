class Solution {
public:
    bool check0(vector<int>&arr,int start, int target, int n,vector<int>&vis){
        if(start > n || start < 0) return false;
        if(vis[start] == 1) return false;
        if(arr[start] == 0) return true;

        vis[start] = 1;
        
        return check0(arr,(start+arr[start]),0,n,vis) || check0(arr,(start-arr[start]),0,n,vis);
    }
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size()-1;
        vector<int>vis(arr.size(),0);
        if(check0(arr,start,0,n,vis) == true) return true;
        return false;
    }
};