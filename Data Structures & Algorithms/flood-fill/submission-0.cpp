class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if (image[sr][sc] == color) {
            return image;
        }

        queue<pair<int, int>> idxQ;
        idxQ.push({sr, sc});

        int oColor = image[sr][sc]; 
        int rows = image.size();
        int cols = image[0].size();

        while (!idxQ.empty()) {
            auto [r, c] = idxQ.front();
            idxQ.pop();

            image[r][c] = color;

            if (r - 1 >= 0 && image[r - 1][c] == oColor) idxQ.push({r - 1, c});
            if (c - 1 >= 0 && image[r][c - 1] == oColor) idxQ.push({r, c - 1});
            if (r + 1 < rows && image[r + 1][c] == oColor) idxQ.push({r + 1, c});
            if (c + 1 < cols && image[r][c + 1] == oColor) idxQ.push({r, c + 1});
        }

        return image;
    }
};