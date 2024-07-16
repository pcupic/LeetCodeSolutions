int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size){

    int totalSize = nums1Size + nums2Size;
    int* mergedArray = (int*)calloc(totalSize, sizeof(int));
    
    for (int i = 0; i < nums1Size; i++) {
        mergedArray[i] = nums1[i];
    }
    
    for (int i = 0; i < nums2Size; i++) {
        mergedArray[nums1Size + i] = nums2[i];
    }
    
    qsort(mergedArray, totalSize, sizeof(int), compare);
    
    double median;
    if (totalSize % 2 != 0) {
        median = mergedArray[totalSize / 2];
    } 
    else {
        median = (mergedArray[totalSize / 2] + mergedArray[totalSize / 2 - 1]) / 2.0;
    }
    
    free(mergedArray);
    mergedArray = NULL;
    
    return median;
}
