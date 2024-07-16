int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}


int* majorityElement(int* nums, int numsSize, int* returnSize) {

    if (numsSize == 0) {
        *returnSize = 0;
        return NULL;
    }

    qsort(nums, numsSize, sizeof(int), compare);

    int* result = (int*)malloc(numsSize * sizeof(int));
    int resultSize = 0;

    int count = 1;
    for (int i = 1; i < numsSize; ++i) {
        if (nums[i] == nums[i - 1]) {
            count++;
        } else {
            if (count > numsSize / 3) {
                result[resultSize++] = nums[i - 1];
            }
            count = 1;
        }
    }
    
    if (count > numsSize / 3) {
        result[resultSize++] = nums[numsSize - 1];
    }

    *returnSize = resultSize;
    return result;
}

