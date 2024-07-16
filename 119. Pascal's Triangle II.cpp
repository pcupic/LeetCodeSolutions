/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int* getRow(int rowIndex, int* returnSize){

    int n = rowIndex + 1;
    int *result = (int*)malloc(n * sizeof(int));

    for(int i = 0; i < n; i++) {
        result[i] = 1;
    }

    *returnSize = n;

    for(int i = 1; i < n - 1; i++) {
        for(int j = i; j > 0; j--) {
            result[j] += result[j - 1];
        }
    }

    return result;
}
