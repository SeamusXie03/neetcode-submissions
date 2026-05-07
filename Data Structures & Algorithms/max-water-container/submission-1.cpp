class Solution {
public:
    int maxArea(vector<int>& heights) {
        int left, right;
        int result;

        left = 0;
        right = heights.size() - 1;

        result = 0;

        while (left < right) {
            int area;

            area = min(heights[left], heights[right]) * (right - left);
            result = max(area, result);

            if (heights[left] < heights[right]) {
                left++;
            } else {
                right--;
            }
        }

        return result;
    }
};
