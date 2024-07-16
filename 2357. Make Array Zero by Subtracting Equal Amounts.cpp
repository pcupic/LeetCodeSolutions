int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int minimumOperations(int* nums, int numsSize){

    if (numsSize == 0) {
        return 0;
    }

    qsort(nums, numsSize, sizeof(int), compare);
    int count = 0;

    for (int i = 0; i < numsSize; i++) {
        if (i == 0 && nums[i] != 0) {
            count++;
        } else if (i > 0 && nums[i] != 0 && nums[i] != nums[i - 1]) {
            count++;
        }
    }

    return count;
}
