class Solution {
public:
    int maxArea(vector<int>& heights) {
        int maxArea = 0;

        int lIdx = 0;
        int rIdx = heights.size() - 1;

        while (lIdx < rIdx) {
            int curArea = min(heights[lIdx], heights[rIdx]) * (rIdx - lIdx);
            
            if (heights[lIdx] < heights[rIdx]) {
                lIdx++;
            } else {
                rIdx--;
            }

            maxArea = max(curArea, maxArea);
        }

        return maxArea;
    }
};
