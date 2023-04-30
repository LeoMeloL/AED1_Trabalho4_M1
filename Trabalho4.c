#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void insertionSort(int arr[], int n) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

int* maxSubsequence(int* nums, int numsSize, int k, int* returnSize){

    int i, j, x = numsSize;

    int *subsequence = (int*)malloc(k * sizeof(int));

    int *final = (int*)malloc(x * sizeof(int));


    memcpy(final, nums, x * sizeof(int));
    insertionSort(final, x);
    
    for (i = x, j = 0; j != k; i--){

            subsequence[j++] = final[i - 1];
    }

    *returnSize = k;
    return subsequence;
}

int main() {
    int nums[] = {-1, 4, 2, -2};
    int k = 3;
    int size = sizeof(nums) / sizeof(nums[0]);
    
    int* subsequence = maxSubsequence(nums, size, k, &size);
    
    printf("Subsequencia de comprimento %d com a maior soma: ", k);
    for (int i = 0; i < k; i++) {
        printf("%d ", subsequence[k-i-1]);
    }
    printf("\n");
    printf("\n");

    free(subsequence);
    
    return 0;
}