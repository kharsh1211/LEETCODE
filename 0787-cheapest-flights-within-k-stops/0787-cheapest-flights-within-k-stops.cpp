class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst,
                          int k) {
        vector<vector<pair<int, int>>> graph(n);
        for (auto& i : flights) {
            graph[i[0]].push_back({i[1], i[2]});
        }

        priority_queue<pair<int, pair<int, int>>,
                       vector<pair<int, pair<int, int>>>,
                       greater<pair<int, pair<int, int>>>>
            pq;

        pq.push({0, {0, src}});
        vector<int> dist(n + 1, INT_MAX);

        while (!pq.empty()) {
            int w = pq.top().first;
            int level = pq.top().second.first;
            int node = pq.top().second.second;
            pq.pop();

            if (node == dst)
                return w;
            if (dist[node] <= level)
                continue;
            dist[node] = level;

                if (level > k) continue;

            for (auto& x : graph[node]) {
                int v = x.first;
                int wt = x.second;
                pq.push({w + wt, {level + 1, v}});
            }
        }
        return -1;
    }
};