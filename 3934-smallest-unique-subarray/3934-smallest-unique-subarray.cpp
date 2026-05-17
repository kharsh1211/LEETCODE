class Solution {
public:
    int smallestUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return 1;
        vector<int> sorted = nums;
        sort(sorted.begin(), sorted.end());
        sorted.erase(unique(sorted.begin(), sorted.end()), sorted.end());
        unordered_map<int, int> val_to_id;
        for (int i = 0; i < sorted.size(); ++i)
            val_to_id[sorted[i]] = i;

        vector<int> rank(n);
        for (int i = 0; i < n; ++i)
            rank[i] = val_to_id[nums[i]];

        vector<int> sa(n);
        iota(sa.begin(), sa.end(), 0);
        vector<int> new_rank(n);

        for (int k = 1; k < n; k <<= 1) {
            vector<pair<int, int>> key(n);
            for (int i = 0; i < n; ++i)
                key[i] = {rank[i], i + k < n ? rank[i + k] : -1};

            sort(sa.begin(), sa.end(),
                 [&](int i, int j) { return key[i] < key[j]; });

            new_rank[sa[0]] = 0;
            for (int i = 1; i < n; ++i)
                new_rank[sa[i]] = new_rank[sa[i - 1]] +
                                   (key[sa[i - 1]] != key[sa[i]]);
            rank = new_rank;
            if (rank[sa[n - 1]] == n - 1) break;
        }

        vector<int> pos(n);
        for (int i = 0; i < n; ++i) pos[sa[i]] = i;
        vector<int> lcp(n - 1);
        int k_lcp = 0;
        for (int i = 0; i < n; ++i) {
            int p = pos[i];
            if (p == n - 1) {
                k_lcp = 0;
                continue;
            }
            int j = sa[p + 1];
            while (i + k_lcp < n && j + k_lcp < n &&
                   nums[i + k_lcp] == nums[j + k_lcp])
                ++k_lcp;
            lcp[p] = k_lcp;
            if (k_lcp) --k_lcp;
        }
        int ans = n;
        for (int i = 0; i < n; ++i) {
            int p = pos[i];
            int maxLCP = 0;
            if (p > 0) maxLCP = max(maxLCP, lcp[p - 1]);
            if (p < n - 1) maxLCP = max(maxLCP, lcp[p]);

            int len_needed = maxLCP + 1;
            if (len_needed <= n - i)
                ans = min(ans, len_needed);
        }
        return ans;
    }
};