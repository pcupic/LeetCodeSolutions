int* spiralOrder(int** data, int matrixSize, int* matrixColSize, int* returnSize){

    int* arr = (int*)calloc(matrixSize * (*matrixColSize), sizeof(int));

    int c1 = 0, c2 = *matrixColSize - 1;
    int r1 = 0, r2 = matrixSize - 1;
    int val = 1;

    int i = 0;
    while(c1 <= c2 && r1 <= r2) {
       
        for(int c = c1; c <= c2; c++) {
            arr[i++] = data[r1][c];
        }

        for(int r = r1 + 1; r <= r2; r++) {
            arr[i++] = data[r][c2];
        }

        if(r1 < r2 && c1 < c2) {
            for(int c = c2 - 1; c > c1; c--) {
                arr[i++] = data[r2][c];
            }

            for(int r = r2; r > r1; r--) {
                arr[i++] = data[r][c1];
            }
        }

        c1++;
        c2--;
        r1++;
        r2--;
    }

    *returnSize = matrixSize * (*matrixColSize);
   
    return arr;
}
