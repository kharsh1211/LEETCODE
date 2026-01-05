class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> grid(numCourses);
        int n = prerequisites.size();
        vector<int> indegree(numCourses, 0);
        for (int i = 0; i < n; i++) {
            int u = prerequisites[i][0];
            int v = prerequisites[i][1];

            grid[v].push_back(u);
            indegree[u]++;
        }
        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }
        vector<int> topo;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            topo.push_back(node);
            for (auto& x : grid[node]) {
                indegree[x]--;
                if (indegree[x] == 0)
                    q.push(x);
            }
        }
        // for(int i=0;i<numCourses;i++){
        //     cout<<topo[i]<<endl;
        // }
        if ((int)topo.size() == numCourses) {
            return topo;
        }
        return {};
    }
};