vector<int> adj[14];
string val;
int N, dp[1 << 14][14][14];

class Solution {
public:
    int dfs(int mask, int i, int j) {
        if (dp[mask][i][j] != -1)
            return dp[mask][i][j];
        int res = 0;
        for (int x : adj[i]) {
            if ((mask >> x) & 1)
                continue;
            for (int y : adj[j]) {
                if ((mask >> y) & 1 || x == y || val[x] != val[y])
                    continue;
                res = max(res, 2 + dfs(mask | (1 << x) | (1 << y), x, y));
            }
        }
        return dp[mask][i][j] = res;
    }

    int maxLen(int n, vector<vector<int>>& edges, string label) {
        ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
        N = n, val = label, memset(dp, -1, sizeof(dp));
        for (int i = 0; i < n; ++i)
            adj[i].clear();
        for (auto& e : edges)
            adj[e[0]].push_back(e[1]), adj[e[1]].push_back(e[0]);

        int ans = 1;
        for (int i = 0; i < n; ++i)
            ans = max(ans, 1 + dfs(1 << i, i, i));

        for (auto& e : edges)
            if (val[e[0]] == val[e[1]])
                ans = max(ans, 2 + dfs((1 << e[0]) | (1 << e[1]), e[0], e[1]));

        return ans;
    }
};