class Solution {
public:
    bool isValid(string s) {
        stack<char> bracket_stack;

        for (char& c : s) {
            if (bracket_stack.empty()) {
                bracket_stack.push(c);
            } else {
                char l = bracket_stack.top();

                if (!isClosed(l, c)) {
                    bracket_stack.push(c);
                } else {
                    bracket_stack.pop();
                }
            }
        }

        return bracket_stack.empty();
    }

    bool isClosed(char l, char r) {
        switch (l) {
            case '[':
                return r == ']';
            case '(':
                return r == ')';
            case '{':
                return r == '}';
            default:
                return false;
        }
    }
};
