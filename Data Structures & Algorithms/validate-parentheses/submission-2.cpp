class Solution {
public:
    bool isValid(string s) {
        stack<char> par_q;

        for (const auto& c : s) {
            if ((c == '(') || (c == '{') || (c == '[')) {
                par_q.push(c);
            } else if (!par_q.empty() && ((par_q.top() == '(' && c == ')') ||
                (par_q.top() == '{' && c == '}') ||
                (par_q.top() == '[' && c == ']'))) {
                par_q.pop();
            } else {
                return false;
            }
        }

        return par_q.size() == 0;
    }
};
