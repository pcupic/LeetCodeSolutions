int compare(const void* a, const void* b) {
    return *(int*)a - *(int*)b;
}

int maximumGap(int* nums, int numsSize) {
    int n = numsSize;
    
    if(n < 2) return 0;

    qsort(nums, n, sizeof(int), compare);

    int max = 0;
    for(int i = 0; i < n - 1; i++) {
        int diff = nums[i + 1] - nums[i];
        if(diff > max)
            max = diff;
    }
    return max;
}
