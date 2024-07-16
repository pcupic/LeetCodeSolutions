int cmpIntervals(const void *a, const void *b) {
    return ((const int **)a)[0][0] - ((const int **)b)[0][0];
}

int eraseOverlapIntervals(int** intervals, int intervalsSize, int* intervalsColSize) {
    qsort(intervals, intervalsSize, sizeof(int*), cmpIntervals);

    int ans = 0;
    int previous = 0;

    for (int current = 1; current < intervalsSize; current++) {
        if (intervals[current][0] < intervals[previous][1]) {
            ans++;
            if (intervals[current][1] <= intervals[previous][1]) {
                previous = current;
            }
        } else {
            previous = current;
        }
    }

    return ans;
}

