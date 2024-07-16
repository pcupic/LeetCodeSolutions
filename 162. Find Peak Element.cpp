int findPeakElement(int* nums, int numsSize){

    int left = 0;
    int right = numsSize - 1;

    while (left < right) {
        int mid = (right + left) / 2;
        if (nums[mid] > nums[mid + 1]) right = mid;
        else left = mid + 1;
    }

    return left; 
}
