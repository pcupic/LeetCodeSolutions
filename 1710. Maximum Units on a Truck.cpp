int compare(const void* a, const void* b) {
    int* boxA = *(int**)a;
    int* boxB = *(int**)b;
    return boxB[1] - boxA[1]; 
}

int maximumUnits(int** boxTypes, int boxTypesSize, int* boxTypesColSize, int truckSize) {
    qsort(boxTypes, boxTypesSize, sizeof(int*), compare);

    int result = 0;

    for (int i = 0; i < boxTypesSize; i++) {
        int boxes = boxTypes[i][0];
        int units = boxTypes[i][1];

        if (truckSize > 0) {
            int take = (truckSize > boxes) ? boxes : truckSize;
            result += take * units;
            truckSize -= take;
        } else {
            break;
        }
    }

    return result;
}
