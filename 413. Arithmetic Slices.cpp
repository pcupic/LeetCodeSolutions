int numberOfArithmeticSlices(int* nums, int numsSize){

    if (numsSize < 3) return 0;

    int count = 0;    
    int currentCount = 0;  
    int diff = nums[1] - nums[0]; 

    for (int i = 2; i < numsSize; i++) {
        if (nums[i] - nums[i - 1] == diff) {
            currentCount++;
            count += currentCount;  
        } else {
            currentCount = 0;
            diff = nums[i] - nums[i - 1];  
        }
    }

    return count;
}
