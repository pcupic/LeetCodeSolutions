bool canJump(int* nums, int numsSize){
    int n = numsSize;
    int index = n - 1;
    for(int i = n - 1; i >= 0; i--) {
        if(nums[i] + i >= index) {
            index = i;
        }
    }
    return index == 0;
}
