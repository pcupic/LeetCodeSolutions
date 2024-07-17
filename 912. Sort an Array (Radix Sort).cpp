/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int findMax(int* array, int size) {
    int max = INT_MIN;
    for (int i = 0; i < size; i++) {
        if (array[i] > max)
            max = array[i];
    }
    return max;
}

void countSortByDigit(int* array, int size, int exp) {
    int* output = (int*)malloc(size * sizeof(int));
    int count[10] = {0};

    for (int i = 0; i < size; i++)
        count[(array[i] / exp) % 10]++;

    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    for (int i = size - 1; i >= 0; i--) {
        output[count[(array[i] / exp) % 10] - 1] = array[i];
        count[(array[i] / exp) % 10]--;
    }

    for (int i = 0; i < size; i++)
        array[i] = output[i];

    free(output);
}

void radixSort(int* array, int size) {
    int max = findMax(array, size);
    for (int exp = 1; max / exp > 0; exp *= 10)
        countSortByDigit(array, size, exp);
}

void reverseArray(int* array, int size) {
    int start = 0, end = size - 1;
    while (start < end) {
        int temp = array[start];
        array[start] = array[end];
        array[end] = temp;
        start++;
        end--;
    }
}

int* sortArray(int* numbers, int size, int* returnSize) {
    int* sortedArray = (int*)malloc(size * sizeof(int));
    if (sortedArray == NULL) {
        *returnSize = 0;
        return NULL;
    }

    int* positives = (int*)malloc(size * sizeof(int));
    int* negatives = (int*)malloc(size * sizeof(int));
    if (positives == NULL || negatives == NULL) {
        free(sortedArray);
        if (positives) free(positives);
        if (negatives) free(negatives);
        *returnSize = 0;
        return NULL;
    }

    int positiveCount = 0, negativeCount = 0;
    for (int i = 0; i < size; i++) {
        if (numbers[i] >= 0)
            positives[positiveCount++] = numbers[i];
        else
            negatives[negativeCount++] = -numbers[i];
    }

    radixSort(positives, positiveCount);
    radixSort(negatives, negativeCount);

    reverseArray(negatives, negativeCount);

    int index = 0;
    for (int i = 0; i < negativeCount; i++)
        sortedArray[index++] = -negatives[i];
    for (int i = 0; i < positiveCount; i++)
        sortedArray[index++] = positives[i];

    free(positives);
    free(negatives);

    *returnSize = size;
    return sortedArray;
}
