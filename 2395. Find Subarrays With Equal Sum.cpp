bool findSubarrays(int* nums, int n){

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 2; j < n; j++) {
            int sum1 = nums[i] + nums[i + 1];
            int sum2 = nums[j - 1] + nums[j];
            if (sum1 == sum2) {
                return true; 
            }
        }
    }
    return false;
}
