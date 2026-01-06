class Solution {
public:
    double bfs(unordered_map<string, vector<pair<string, double>>>& mp,
               string s, string e) {
        if (mp.find(s) == mp.end() || mp.find(e) == mp.end())
            return -1.0;

        if (s == e)
            return 1.0;
        queue<pair<string, double>> q;
        unordered_set<string> vis;

        q.push({s, 1.0});
        vis.insert(s);

        while (!q.empty()) {
            string node = q.front().first;
            double dist_node = q.front().second;
            q.pop();

            for (auto& x : mp[node]) {
                string x1 = x.first;
                double d = x.second;
                double new_d = d * dist_node;

                if (vis.find(x1) == vis.end()) {
                    double new_d = dist_node * d;
                    if (x1 == e) {
                        return new_d;
                    }
                    vis.insert(x1);
                    q.push({x1, new_d});
                }
            }
        }
        return -1.0;
    }

    vector<double> calcEquation(vector<vector<string>>& equations,
                                vector<double>& values,
                                vector<vector<string>>& queries) {
        unordered_map<string, vector<pair<string, double>>> mp;
        vector<double> ans;

        for (int i = 0; i < equations.size(); i++) {
            string u = equations[i][0];
            string v = equations[i][1];
            double w = values[i];

            mp[u].push_back({v, w});
            mp[v].push_back({u, 1.0 / w});
        }
        for (int i = 0; i < queries.size(); i++) {
            string s = queries[i][0];
            string e = queries[i][1];
            ans.push_back(bfs(mp, s, e));
        }
        return ans;
    }
};