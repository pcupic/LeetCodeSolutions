void markIsland(char **grid, int m, int n, int i, int j) {

    if(i < 0 || j < 0 || i >= m || j >= n || grid[i][j] == '0') 
        return;
    grid[i][j] = '0';

    markIsland(grid, m, n, i + 1, j);
    markIsland(grid, m, n, i - 1, j);
    markIsland(grid, m, n, i, j + 1);
    markIsland(grid, m, n, i, j - 1);
}

int numIslands(char** grid, int gridSize, int* gridColSize) {
    
    int count = 0;
    int m = gridSize;
    int n = *gridColSize;
    
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(grid[i][j] == '1') {
                markIsland(grid, m, n, i, j);
                count++;
            }    
        }
    }
    return count;
}
