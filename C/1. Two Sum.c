#include <stdio.h>
#include <stdlib.h>

int* twoSum(int* nums, int n, int target, int* returnSize) {
    *returnSize = 2; // We expect to return two indices
    for(int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (nums[i] + nums[j] == target) {
                int* result = (int*)malloc(*returnSize * sizeof(int));
                result[0] = i;
                result[1] = j;
                return result;
            }
        }
    }
    return NULL; // Return NULL if no solution is found
}

int main() {
    int nums[] = {2, 7, 11, 15};
    int target = 9;
    int returnSize;
    
    int* indices = twoSum(nums, sizeof(nums)/sizeof(nums[0]), target, &returnSize);
    
    if (indices != NULL) {
        printf("Indices found: %d and %d\n", indices[0], indices[1]);
        free(indices); // Free allocated memory
    } else {
        printf("No two sum solution found.\n");
    }

    return 0;
}

