int minPatches(int* nums, int numsSize, int n){
    long reach = 0;
    int i = 0;
    int count = 0;
    while(reach < n) {
        if(i >= numsSize) {
            count++;
            reach += reach + 1;
        }
        else if(i < numsSize && nums[i] <= 1 + reach) {
            reach += nums[i];
            i++;
        }
        else {
            count++;
            reach += reach + 1;
        }
    }
    return count;
}
