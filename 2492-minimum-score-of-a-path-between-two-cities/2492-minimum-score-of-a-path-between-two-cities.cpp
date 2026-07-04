class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        
        vector<vector<pair<int,int>>>Roads(n+1);

        for(auto &it:roads){
            int u = it[0];
            int v = it[1];
            int w = it[2];

            Roads[u].push_back({v,w});
            Roads[v].push_back({u,w});
        }

        // 1 --> 2,4 --> min(9,5) --> 5
        // 2 --> 3,4 --> min()

        vector<int>vis(n+1,0);
        queue<int>q;

        int min_score = INT_MAX;

        vis[1] = 1;;
        q.push(1);

        while(!q.empty()){
            int parent = q.front();
            q.pop();

            for(auto &adj_node:Roads[parent]){
                int to_go = adj_node.first;
                int weight = adj_node.second;
                
                min_score = min(min_score,weight);

                if(!vis[to_go]){
                    vis[to_go] = 1;
                    q.push(to_go);
                }
            }
        }
        return min_score;
    }
};