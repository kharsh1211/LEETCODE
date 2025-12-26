class Solution {
public:
    long long minMoves(vector<int>& balance) {
        int n = balance.size();

        long long sum = 0;
        for (int x : balance) sum += x;
        if (sum < 0) return -1;

        int pivot = 0;
        for (int i = 1; i < n; i++) {
            if (balance[i] < balance[pivot]) {
                pivot = i;
            }
        }

        if (balance[pivot] >= 0) return 0;

        long long need = -1LL * balance[pivot];
        long long moves = 0;

        int left = (pivot - 1 + n) % n;
        int right = (pivot + 1) % n;
        int dist = 1;

        while (need > 0) {
            if (left == right) {
                long long take = min(need, (long long)balance[left]);
                moves += take * dist;
                need -= take;
                break;
            }

            if (balance[left] > 0 && need > 0) {
                long long take = min(need, (long long)balance[left]);
                moves += take * dist;
                need -= take;
                balance[left] -= (int)take;
            }

            if (balance[right] > 0 && need > 0) {
                long long take = min(need, (long long)balance[right]);
                moves += take * dist;
                need -= take;
                balance[right] -= (int)take;
            }

            left = (left - 1 + n) % n;
            right = (right + 1) % n;
            dist++;
        }

        return moves;
    }
};
