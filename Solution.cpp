
#include <array>
#include <queue>
#include <vector>
using namespace std;

class Solution {

    struct Point {
        int row{};
        int column{};
        Point(int row, int column) : row {row}, column {column} {}
    };
    
    inline static const array<array<int, 2>, 8> moves { {{-1, -2}, {-2, -1}, {-2, 1}, {-1, 2}, {1, -2}, {2, -1}, {2, 1}, {1, 2}} };
    inline static const array<int, 2> TARGET_RANGE {-300, 300};
    inline static const int OFFSET = 300 + 2; //we might need to go maximum 2 points behind target range.


public:
    int minKnightMoves(int targetRow, int tagargetColumn) {
        vector<vector<bool>> visited(2 * OFFSET + 1, vector<bool>(2 * OFFSET + 1));
        queue<Point> queue;
        queue.push(Point(0, 0));
        visited[0 + OFFSET][0 + OFFSET] = true;
        
        int movesFromStart = 0;
        bool goalReached = false;

        while (!queue.empty()) {

            for (int i = queue.size() - 1; i >= 0; --i) {
                Point point = queue.front();
                queue.pop();

                if (point.row == targetRow && point.column == tagargetColumn) {
                    goalReached = true;
                    break;
                }

                for (const auto& move : moves) {
                    int nextRow = point.row + move[0];
                    int nextColumn = point.column + move[1];

                    if (!visited[nextRow + OFFSET][nextColumn + OFFSET]) {
                        visited[nextRow + OFFSET][nextColumn + OFFSET] = true;
                        queue.push(Point(nextRow, nextColumn));
                    }
                }
            }

            if (goalReached) {
                break;
            }
            ++movesFromStart;
        }
        return movesFromStart;
    }
};
