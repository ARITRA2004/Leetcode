class Solution {
public:

    int bfs(int node, vector<vector<int>> &adj, vector<int> &vis){
        queue<int>q;

        int edges = 0;
        int nodes = 0;

        q.push(node);
        vis[node] = 1;

        while(!q.empty()){
            int u = q.front();
            q.pop();
            nodes++;
            edges = edges + adj[u].size();

            for(auto &node: adj[u]){
                if(!vis[node]){
                    q.push(node);
                    vis[node] = 1;
                    
                }
            }
        }
        edges /= 2;

        return edges == nodes * (nodes - 1) / 2;
    }

    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<int>vis(n,0);
        int ans = 0;
        vector<vector<int>>adj(n);

        for (auto &e : edges) {
            int u = e[0];
            int v = e[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        for(int i=0;i<n;i++){
            if(!vis[i]){
                ans += bfs(i,adj,vis);
            }else{
                continue;
            }
        }
        return ans;
    }
};