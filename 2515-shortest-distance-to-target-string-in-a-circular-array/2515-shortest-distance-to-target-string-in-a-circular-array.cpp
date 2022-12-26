class Solution {
public:
    int closetTarget(vector<string>& words, string target, int startIndex) {
        int n = words.size();
    int left = startIndex, right = startIndex;
    int steps = 0;
    while (true) {
        if (words[left] == target || words[right] == target) {
            return steps;
        }
        left = (left - 1 + n) % n;
        right = (right + 1) % n;
        steps++;
        if (left == startIndex && right == startIndex) {
            break;
        }
    }
    return -1;
    }
};