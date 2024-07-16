int longestMountain(int* arr, int arrSize){

    int ans = 0;
    int n = arrSize;

    for(int i = 1; i <= n - 2;) {
        if(arr[i] > arr[i - 1] && arr[i] > arr[i + 1]) {
            int count = 1;
            int j = i;
            while(j > 0 && arr[j] > arr[j - 1]) {
                j--;
                count++;
            }
            while(i < n - 1 && arr[i] > arr[i + 1]) {
                i++;
                count++;
            }
            if(count > ans) ans = count;
        }
        else {
            i++;
        }
    }
    return ans;
}
