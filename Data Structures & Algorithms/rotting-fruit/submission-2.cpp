class Solution {
public:
    static constexpr int FRESH  = 1;
    static constexpr int ROTTEN = 2;

    int orangesRotting(vector<vector<int>>& grid) {
        int time = 0;
        int fresh = 0;

        queue<pair<int, int>> rottenQ;

        int rows = grid.size();
        int cols = grid[0].size();

        for (int rIdx = 0; rIdx < rows; rIdx++) {
            for (int cIdx = 0; cIdx < cols; cIdx++) {
                if (grid[rIdx][cIdx] == ROTTEN) {
                    rottenQ.push({rIdx, cIdx});
                } else if (grid[rIdx][cIdx] == FRESH) {
                    fresh++;
                }
            }
        }

        while (!rottenQ.empty()) {
            int size = rottenQ.size();

            for (int i = 0; i < size; i++) {
                auto [r, c] = rottenQ.front();
                rottenQ.pop();

                // top
                if (r - 1 >= 0 && grid[r - 1][c] == FRESH) {
                    grid[r - 1][c] = ROTTEN;
                    fresh--;
                    rottenQ.push({r - 1, c});
                }

                // bottom
                if (r + 1 < rows && grid[r + 1][c] == FRESH) {
                    grid[r + 1][c] = ROTTEN; 
                    fresh--;
                    rottenQ.push({r + 1, c});
                }

                // left
                if (c - 1 >= 0 && grid[r][c - 1] == FRESH) {
                    grid[r][c - 1] = ROTTEN;
                    fresh--;
                    rottenQ.push({r, c - 1});
                }

                // right
                if (c + 1 < cols && grid[r][c + 1] == FRESH) {
                    grid[r][c + 1] = ROTTEN;
                    fresh--;
                    rottenQ.push({r, c + 1});
                }
            }

            if (!rottenQ.empty()) {
                time++;
            }
        } 

        return fresh == 0 ? time : -1;
    }
};
