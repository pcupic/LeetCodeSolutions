void reverse(int* arr, int start, int end) {
    while (start < end) {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}

void rotate(int* arr, int size, int steps){
    steps = steps % size;
    if (steps == 0) return;

    reverse(arr, 0, size - 1);
    reverse(arr, 0, steps - 1);
    reverse(arr, steps, size - 1);
}
