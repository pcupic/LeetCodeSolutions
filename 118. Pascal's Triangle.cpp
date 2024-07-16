/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** generate(int numRows, int* returnSize, int** returnColumnSizes){

    *returnSize = numRows;
    *returnColumnSizes = (int*)malloc(numRows * sizeof(int));    
    int **matrix = (int**)malloc(numRows * sizeof(int*));
    for(int i = 0; i < numRows; i++) {
        matrix[i] = (int*)malloc((i + 1) * sizeof(int));
        (*returnColumnSizes)[i] = i + 1;
        for(int j = 0; j <= i; j++) {
            if(j == 0 || j == i) 
                matrix[i][j] = 1;
            else
                matrix[i][j] = matrix[i - 1][j] + matrix[i - 1][j - 1];
        }
    }
    return matrix;
}
