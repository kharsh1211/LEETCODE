class Solution {
public:

    int findMaxRequests(int ind, int taken, vector<int> &delta, int n, vector<vector<int>> &requests) {

        if(ind == n) {
            
            for(auto it : delta) {
                if(it != 0) {
                    return 0;
                }
            }

            return taken;
        }

        int from = requests[ind][0];
        int to = requests[ind][1];

        delta[from]--;
        delta[to]++;
        int res = findMaxRequests(ind + 1, taken + 1, delta, n, requests);
        delta[to]--;
        delta[from]++;

        res = max(res, findMaxRequests(ind + 1, taken, delta, n, requests));

        return res;

    }

    int maximumRequests(int buildings_count, vector<vector<int>>& requests) {
        
        int n = requests.size();
        vector<int> delta(buildings_count, 0);

        return findMaxRequests(0, 0, delta, n, requests);

    }
};