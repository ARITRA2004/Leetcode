class Solution {
public:
    void bfs(int node, vector<vector<int>>&adj, vector<int>&vis) {
        queue<int> q;

        vis[node] = 1;
        q.push(node);

        while (!q.empty()) {

            int ele = q.front();
            q.pop();

            for (auto it : adj[ele]) {
                if (vis[it] != 1) {
                    vis[it] = 1;
                    q.push(it);
                }
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int V = isConnected.size();
        vector<vector<int>>adj(V);
        vector<int> vis(V, 0);

        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (isConnected[i][j] == 1 && i != j) {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        int count = 0;

        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                count++;
                bfs(i, adj, vis);
            }
        }
        return count;
    }
};