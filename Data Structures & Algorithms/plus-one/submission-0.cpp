class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        stack<int> dStack;

        for (int& digit : digits) {
            dStack.push(digit);
        }

        stack<int> revStack;
        bool carry = true;
        
        while (!dStack.empty()) {
            int digit = dStack.top();
            dStack.pop();

            if (carry) {
                digit += 1;

                if (digit == 10) {
                    digit = 0;
                } else {
                    carry = false;
                }
            }

            revStack.push(digit);
        }

        if (carry) {
            revStack.push(1);
        }

        vector<int> result;
        while (!revStack.empty()) {
            result.push_back(revStack.top());
            revStack.pop();
        }

        return result;
    }
};
