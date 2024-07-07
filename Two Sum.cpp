int* twoSum(int* nums, int n, int target, int* returnSize){

    *returnSize = 2;
    for(int i = 0; i < n - 1; i++) {
        for(int j = i + 1; j < n; j++) {
            if(nums[i] + nums[j] == target) {
                nums[0] = i;
                nums[1] = j;
                return nums;
            }
        }
    }
    return NULL;
}

