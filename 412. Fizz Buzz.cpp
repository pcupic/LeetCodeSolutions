#include <stdio.h>
#include <stdlib.h>

char** fizzBuzz(int n, int* returnSize) {
    char** answer = (char**)calloc(n, sizeof(char*));
    *returnSize = n;

    for (int i = 1; i <= n; i++) {
        answer[i - 1] = (char*)calloc(9, sizeof(char));
        if (i % 3 == 0 && i % 5 == 0) {
            strcpy(answer[i - 1], "FizzBuzz");
        } else if (i % 3 == 0) {
            strcpy(answer[i - 1], "Fizz");
        } else if (i % 5 == 0) {
            strcpy(answer[i - 1], "Buzz");
        } else {
            snprintf(answer[i - 1], 9, "%d", i);
        }
    }

    return answer;
}

