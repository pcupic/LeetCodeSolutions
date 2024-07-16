/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** generateMatrix(int n, int* returnSize, int** returnColumnSizes){

    int** data = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        data[i] = (int*)malloc(n * sizeof(int));
    }

    int c1 = 0, c2 = n - 1;
    int r1 = 0, r2 = n - 1;
    int val = 1;

    while(c1 <= c2 && r1 <= r2) {
       
        for(int c = c1; c <= c2; c++) {
            data[r1][c] = val++;
        }

        for(int r = r1 + 1; r <= r2; r++) {
            data[r][c2] = val++;
        }

        if(r1 < r2 && c1 < c2) {
            for(int c = c2 - 1; c > c1; c--) {
                data[r2][c] = val++;
            }

            for(int r = r2; r > r1; r--) {
                data[r][c1] = val++;
            }
        }

        c1++;
        c2--;
        r1++;
        r2--;
    }

    *returnSize = n;
    *returnColumnSizes = (int*)malloc(n * sizeof(int));
    for(int i = 0; i < n; i++) {
        (*returnColumnSizes)[i] = n;
    }
    return data;
}
