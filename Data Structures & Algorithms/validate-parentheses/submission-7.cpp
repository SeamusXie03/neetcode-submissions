class Solution {
public:
    bool isValid(string s) {
        stack<char> pStack;

        for (char& c : s) {
            if (pStack.empty()) {
                pStack.push(c);
            } else {
                char& l = pStack.top();

                if (isClosed(l, c)) {
                    pStack.pop();
                } else {
                    pStack.push(c);
                }
            }
        }

        return pStack.empty();
    }

    bool isClosed(const char& l, const char& r) {
        if (l == '[') {
            return r == ']';
        }

        if (l == '(') {
            return r == ')';
        }

        if (l == '{') {
            return r == '}';
        }

        return false;
    }
};
