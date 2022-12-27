class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        vector<string> result;
  unordered_set<string> visited;
  queue<string> q;

  // Add the original string to the queue
  q.push(s);
  visited.insert(s);

  // Perform a BFS to explore all possible strings
  bool found = false;
  while (!q.empty()) {
    string str = q.front();
    q.pop();

    // Check if the current string is valid
    int count = 0;
    for (char c : str) {
      if (c == '(') {
        count++;
      } else if (c == ')') {
        count--;
      }
      if (count < 0) {
        break;
      }
    }

    if (count == 0) {
      // If the string is valid, add it to the result and mark the search as complete
      result.push_back(str);
      found = true;
    }

    if (!found) {
      // If the string is invalid and the search is not complete, try removing one parenthesis at a time
      for (int i = 0; i < str.length(); i++) {
        if (str[i] == '(' || str[i] == ')') {
          string next = str.substr(0, i) + str.substr(i + 1);
          if (visited.count(next) == 0) {
            q.push(next);
            visited.insert(next);
          }
        }
      }
    }
  }

  return result;  
    }
};