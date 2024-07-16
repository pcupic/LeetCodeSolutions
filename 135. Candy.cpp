int candy(int* ratings, int ratingsSize){
    int n = ratingsSize;
    int *left = (int*)calloc(n, sizeof(int));
    int *right = (int*)calloc(n, sizeof(int));

    for(int i = 0; i < n; i++) {
        left[i] = 1;
        right[i] = 1;
    }

    for(int i = 1; i < n; i++) {
        if(ratings[i] > ratings[i - 1])
            left[i] = left[i - 1] + 1;
    }
    for(int i = n - 2; i >= 0; i--) {
        if(ratings[i] > ratings[i + 1])
            right[i] = right[i + 1] + 1;
    }

    int total = 0;
    for(int i = 0; i < n; i++) {
        if(left[i] > right[i])
            total += left[i];
        else
            total += right[i];
    }

    return total;
}
