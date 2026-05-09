class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        // temperature -> index
        stack<pair<int, int>> temInStack;
        temInStack.push({temperatures[0], 0});

        vector<int> result(temperatures.size(), 0);

        for (int idx = 1; idx < temperatures.size(); idx++) {
            while (!temInStack.empty()) {
                auto& [temp, i] = temInStack.top();

                if (temp < temperatures[idx]) {
                    result[i] = idx - i;
                    temInStack.pop();
                } else {
                    break;
                }
            }

            temInStack.push({temperatures[idx], idx});
        }

        return result;
    }
};
