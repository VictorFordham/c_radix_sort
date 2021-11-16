#include <stdio.h>
#include <stdlib.h>
#include "containers/bucket/bucket.h"

int arr[] = {
    45, 432, 1, 0, 242, 897, 10, 100, 56,
    123456, 6544321, 12, 343, 525, 13124,
};

void radix_sort(int* nums, int num_len) {
    int* _nums = malloc(sizeof(int) * num_len);

    for (int i = 0; i < num_len; i++)
        _nums[i] = nums[i];

    Bucket bucket = Bucket_new();
    
    for (int shift = 0; shift < 4; shift++) {

        for (int i = 0; i < num_len; i++) {
            int val = _nums[i];
            Bucket_add(&bucket,(val >> (shift << 3)) & 0xff, val);
        }
        Bucket_empty(&bucket, _nums);
    }
    
    for (int i = 0; i < num_len; i++)
        nums[i] = _nums[i];

    free(_nums);
}

int main() {
    int arr_len = sizeof(arr) >> 2;

    for (int i = 0; i < arr_len; i++)
        printf("%d, ", arr[i]);
    puts("\n");

    radix_sort(arr, arr_len);

    for (int i = 0; i < arr_len; i++)
        printf("%d, ", arr[i]);
    puts("\n");

    return 0;
}