class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights,
                          int src, int dst, int k) {

        vector<int> dist(n, INT_MAX);
        dist[src] = 0;

        // k stops allow at most k + 1 flights.
        for (int i = 0; i <= k; i++) {
            vector<int> temp = dist;

            for (int j = 0; j < flights.size(); j++) {
                int u = flights[j][0];
                int v = flights[j][1];
                int price = flights[j][2];

                if (dist[u] != INT_MAX) {
                    temp[v] = min(temp[v], dist[u] + price);
                }
            }

            dist = temp;
        }

        return dist[dst] == INT_MAX ? -1 : dist[dst];
    }
};