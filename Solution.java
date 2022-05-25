
import java.util.LinkedList;
import java.util.Queue;

public class Solution {

    private static record Point(int row, int column) {}
    private static final int[][] moves = {{-1, -2}, {-2, -1}, {-2, 1}, {-1, 2}, {1, -2}, {2, -1}, {2, 1}, {1, 2}};
    private static final int[] TARGET_RANGE = {-300, 300};
    private static final int OFFSET = 300 + 2;//we might need to go maximum 2 points behind target range.

    public int minKnightMoves(int targetRow, int tagargetColumn) {

        boolean[][] visited = new boolean[2 * OFFSET + 1][2 * OFFSET + 1];
        Queue<Point> queue = new LinkedList<>();
        queue.add(new Point(0, 0));
        visited[0 + OFFSET][0 + OFFSET] = true;
        
        int movesFromStart = 0;
        boolean goalReached = false;

        while (!queue.isEmpty()) {

            for (int i = queue.size() - 1; i >= 0; --i) {
                Point point = queue.poll();
                if (point.row == targetRow && point.column == tagargetColumn) {
                    goalReached = true;
                    break;
                }

                for (int[] move : moves) {
                    int nextRow = point.row + move[0];
                    int nextColumn = point.column + move[1];

                    if (!visited[nextRow + OFFSET][nextColumn + OFFSET]) {
                        visited[nextRow + OFFSET][nextColumn + OFFSET] = true;
                        queue.add(new Point(nextRow, nextColumn));
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
}
