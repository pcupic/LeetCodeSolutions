int singleNumber(int* nums, int numsSize){
    int n = numsSize;
    int xor = 0;
    for(int i = 0; i < n; i++) 
        xor = xor ^ nums[i];

    return xor;      
}
