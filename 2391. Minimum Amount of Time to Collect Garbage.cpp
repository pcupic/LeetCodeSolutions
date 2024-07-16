int garbageCollection(char ** garbage, int garbageSize, int* travel, int travelSize){

    int* prefixSums = (int*)calloc(travelSize, sizeof(int));

    prefixSums[0] = travel[0];
    for(int i = 1; i < travelSize; i++) {
        prefixSums[i] = prefixSums[i - 1] + travel[i];
    } 

    int ans = 0;
    int p = 0;
    int g = 0;
    int m = 0;

    for(int i = 0; i < garbageSize; i++) {
        char *current = garbage[i];
        int len = strlen(current);
        for(int j = 0; j < len; j++) {
            if(current[j] == 'G') g = i;
            if(current[j] == 'M') m = i;
            if(current[j] == 'P') p = i;
        }
        ans += len;
    }

    if(g >= 1) ans += prefixSums[g - 1];
    if(p >= 1) ans += prefixSums[p - 1];
    if(m >= 1) ans += prefixSums[m - 1];

    return ans;
}
