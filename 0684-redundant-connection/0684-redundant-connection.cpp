class Solution {
public:
    bool dfscycle(int parent, vector<vector<int>>& adj,
                  int vertex, vector<int>& visited)
    {
        visited[vertex] = 1;

        for (int i = 0; i < adj[vertex].size(); i++)
        {
            int neighbor = adj[vertex][i];

            if (visited[neighbor] == 0)
            {
                if (dfscycle(vertex, adj, neighbor, visited))
                    return true;
            }
            else if (neighbor != parent)
            {
                return true;
            }
        }

        return false;
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges)
    {
        int n = edges.size();
        vector<vector<int>> adj(n + 1);

        for (int i = 0; i < n; i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];

            adj[u].push_back(v);
            adj[v].push_back(u);

            vector<int> visited(n + 1, 0);

            if (dfscycle(-1, adj, u, visited))
                return edges[i];
        }

        return {};
    }
};