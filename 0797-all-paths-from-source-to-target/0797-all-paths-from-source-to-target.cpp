class Solution {
public:

    void dfs(int node, vector<vector<int>>graph, vector<vector<int>>&res,vector<int>&path){

        path.push_back(node);

        if(node == graph.size()-1){
            res.push_back(path);
        }
        else{
            for(int child:graph[node]){
                dfs(child,graph,res,path);
            }
        }
        path.pop_back();
    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {

        int n = graph.size();
        int m = graph[0].size();

        vector<vector<int>>res;
        vector<int>path;

        dfs(0,graph,res,path);

        return res;
    }
};