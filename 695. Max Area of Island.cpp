int max(int a, int b) {
    return a > b ? a : b;
}

int dfs(int **grid, int **visited, int row, int col, int i, int j) {

    if(i < 0 || j < 0 || i >= row || j >= col || !grid[i][j] || visited[i][j]) 
        return 0;
    
    visited[i][j] = 1;
    return 1 + dfs(grid, visited, row, col, i + 1, j) + 
                dfs(grid, visited, row, col, i - 1, j) +
                dfs(grid, visited, row, col, i, j + 1) +
                dfs(grid, visited, row, col, i, j - 1);
}

int maxAreaOfIsland(int** grid, int gridSize, int* gridColSize) {
    int result = 0;
    int row = gridSize;
    int col = *gridColSize;

    int** visited = (int**)calloc(row, sizeof(int*));
    for(int i = 0; i < row; i++) {
        visited[i] = (int*)calloc(col, sizeof(int));
    }

    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {
            if(grid[i][j])
                result = max(result, dfs(grid, visited, row, col, i, j));
        }
    }

    return result;
}
