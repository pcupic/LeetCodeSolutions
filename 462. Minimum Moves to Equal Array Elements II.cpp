int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int minMoves2(int* nums, int numsSize){
    
    qsort(nums, numsSize, sizeof(int), compare);
    int start = 0;
    int end = numsSize - 1;
    int count = 0;
    while(start < end) {
        count += abs(nums[end] - nums[start]);
        start++;
        end--;
    }
    return count;
}
