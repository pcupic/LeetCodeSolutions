int min(int x, int y) {
    return x < y ? x : y;
}

int maxArea(int* height, int w){

    int start = 0;
    int end = w - 1;
    int area = 0;
    int max_area = 0;
    while(start < end) {
        area = min(height[start], height[end]) * (end - start);
        if(area > max_area) {
            max_area = area;
        }
        if(min(height[start], height[end]) == height[start]) start++;
        else end--;
    }
    
    return max_area;
}
