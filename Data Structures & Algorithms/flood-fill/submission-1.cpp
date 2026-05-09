class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if (image[sr][sc] == color) {
            return image;
        }

        int oColor = image[sr][sc]; 

        queue<pair<int, int>> idxQ;
        image[sr][sc] = color;
        idxQ.push({sr, sc});
        
        int rows = image.size();
        int cols = image[0].size();

        while (!idxQ.empty()) {
            auto [r, c] = idxQ.front();
            idxQ.pop();

            if (r - 1 >= 0 && image[r - 1][c] == oColor) {
                image[r - 1][c] = color;
                idxQ.push({r - 1, c});
            }

            if (c - 1 >= 0 && image[r][c - 1] == oColor) {
                image[r][c - 1] = color;
                idxQ.push({r, c - 1});
            }

            if (r + 1 < rows && image[r + 1][c] == oColor) {
                image[r + 1][c] = color;
                idxQ.push({r + 1, c});
            }

            if (c + 1 < cols && image[r][c + 1] == oColor) {
                image[r][c + 1] = color;
                idxQ.push({r, c + 1});
            }
        }

        return image;
    }
};