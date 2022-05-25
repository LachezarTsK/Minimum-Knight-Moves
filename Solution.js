
/**
 * @param {number} targetRow
 * @param {number} tagargetColumn
 * @return {number}
 */
var minKnightMoves = function (targetRow, tagargetColumn) {
    const moves = [[-1, -2], [-2, -1], [-2, 1], [-1, 2], [1, -2], [2, -1], [2, 1], [1, 2]];
    const TARGET_RANGE = [-300, 300];
    const OFFSET = 300 + 2;//we might need to go maximum 2 points behind target range.

    const visited = Array.from(new Array(2 * OFFSET + 1), () => new Array(2 * OFFSET + 1).fill(false));
    const queue = new Queue();
    queue.enqueue(new Point(0, 0));
    visited[0 + OFFSET][0 + OFFSET] = true;

    let movesFromStart = 0;
    let goalReached = false;

    while (!queue.isEmpty()) {

        for (let i = queue.size() - 1; i >= 0; --i) {
            const point = queue.dequeue();
            if (point.row === targetRow && point.column === tagargetColumn) {
                goalReached = true;
                break;
            }

            for (let move of moves) {
                let nextRow = point.row + move[0];
                let nextColumn = point.column + move[1];

                if (!visited[nextRow + OFFSET][nextColumn + OFFSET]) {
                    visited[nextRow + OFFSET][nextColumn + OFFSET] = true;
                    queue.enqueue(new Point(nextRow, nextColumn));
                }
            }
        }
        
        if (goalReached) {
            break;
        }
        ++movesFromStart;
    }
    return movesFromStart;
};

/**
 * @param {number} row
 * @param {number} column
 */
function Point(row, column) {
    this.row = row;
    this.column = column;
}
