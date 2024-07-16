int min(int x, int y) {
    return x < y ? x : y;
} 

int trap(int* height, int n){

    int left[n];
    int right[n];
    int lmax = 0;
    int rmax = 0;
    int trapped = 0;
    
    for(int i = 0; i < n; i++)
    {
       if(lmax < height[i]) {
           lmax = height[i];
       }
       left[i] = lmax;
    }

    for(int i = n - 1; i >= 0; i--) {
        if(rmax < height[i]) {
            rmax = height[i];
        }
        right[i] = rmax;
    }

    for(int i = 0; i < n; i++) {
        trapped += min(left[i], right[i]) - height[i]; 
    }

    return trapped;
}
