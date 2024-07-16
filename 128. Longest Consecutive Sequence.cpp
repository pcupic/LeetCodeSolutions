int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b); 
}

int max(int a, int b) {
    return a > b ? a : b;
}

int longestConsecutive(int* nums, int numsSize) {
    if (numsSize == 0) {
        return 0;
    }

    qsort(nums, numsSize, sizeof(int), compare);

    int Max = 1;  
    int count = 1;  

    for (int i = 1; i < numsSize; i++) {
        if (nums[i] == nums[i - 1] + 1) {
            count++;
        } else if(nums[i] != nums[i - 1]) {
            Max = max(count, Max);
            count = 1;
        }
    }

    return max(count, Max);
}

