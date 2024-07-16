void markConnectedRegions(int row, int col, int m, int n, char** board, bool** visited) {
    if (row == m || col == n || row < 0 || col < 0 || visited[row][col] || 
        board[row][col] != 'O')
        return;

    visited[row][col] = true;
    board[row][col] = 'A';

    if (row + 1 < m) markConnectedRegions(row + 1, col, m, n, board, visited);
    if (row - 1 >= 0) markConnectedRegions(row - 1, col, m, n, board, visited);
    if (col + 1 < n) markConnectedRegions(row, col + 1, m, n, board, visited);
    if (col - 1 >= 0) markConnectedRegions(row, col - 1, m, n, board, visited);
}

void solve(char** board, int boardSize, int* boardColSize){
    int i, j, m = boardSize, n = *boardColSize;

    bool **visited = (bool**)calloc(sizeof(bool*), m);

    for (i = 0; i < m; i++)
        visited[i] = (bool*)calloc(sizeof(bool), n);

    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            if (board[i][j] == 'O' && (i == m - 1 || j == n - 1 || i == 0 || j == 0)) {
                markConnectedRegions(i, j, m, n, board, visited);
            }
        }
    }

    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            if (board[i][j] == 'A')
                board[i][j] = 'O';
            else if (board[i][j] == 'O')
                board[i][j] = 'X';
        }
    }
}
