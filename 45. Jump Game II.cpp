int max(int a, int b) {
    return a < b ? b : a;
}

int jump(int* nums, int n){
    int farthest = 0;
    int jumps = 0;
    int current = 0;
    for(int i = 0; i < n - 1; i++) {
        farthest = max(farthest, nums[i] + i);
        if(i == current) {
            current = farthest;
            jumps++;
        }
    }
    return jumps;
}
