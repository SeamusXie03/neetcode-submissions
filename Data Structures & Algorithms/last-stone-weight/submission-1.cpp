class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> stoneQ;
        stoneQ.push(0);

        for (int& stone : stones) {
            stoneQ.push(stone);
        }

        while (stoneQ.size() > 1) {
            int x = stoneQ.top();
            stoneQ.pop();

            int y = stoneQ.top();
            stoneQ.pop();

            if (x > y) {
                stoneQ.push(x - y);
            }
        }

        return stoneQ.top();
    }
};
