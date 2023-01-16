class Solution {
public:
    // dsu
    vector<int> root;
    int get(int x) {
        return x == root[x] ? x : (root[x] = get(root[x]));
    }
    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
        // each node is a good path
        int n = vals.size(), ans = n;
        vector<int> cnt(n, 1);
        root.resize(n);
        // each element is in its own group initially
        for (int i = 0; i < n; i++) root[i] = i;
        // sort by vals
        sort(edges.begin(), edges.end(), [&](const vector<int>& x, const vector<int>& y) {
           return max(vals[x[0]], vals[x[1]]) < max(vals[y[0]], vals[y[1]]);
        });
        // iterate each edge
        for (auto e : edges) {
            int x = e[0], y = e[1];
            // get the root of x
            x = get(x);
            // get the root of y
            y = get(y);
            // if their vals are same, 
            if (vals[x] == vals[y]) {
                // then there would be cnt[x] * cnt[y] good paths
                ans += cnt[x] * cnt[y];
                // unite them
                root[x] = y;
                // add the count of x to that of y
                cnt[y] += cnt[x];
            } else if (vals[x] > vals[y]) {
                // unite them
                root[y] = x;
            } else {
                // unite them
                root[x] = y;
            }
        }
        return ans;
    }
};