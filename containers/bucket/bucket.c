#include "bucket.h"

Bucket Bucket_new() {
    LinkedList* lists = malloc(sizeof(LinkedList) * 256);

    for (int i = 0; i < 256; i++)
        lists[i] = LinkedList_new();
    
    Bucket out = {
        .lists=lists,
    };

    return out;
}

void Bucket_free(Bucket* bucket) {
    free(bucket->lists);
}

void Bucket_add(Bucket* bucket, int index, int val) {
    LinkedList_add(&bucket->lists[index], val);
}

void Bucket_empty(Bucket* bucket, int* arr) {
    int index = 0;

    for (int i = 0; i < 256; i++) {
        for (Iterator iter = LinkedList_iter(&bucket->lists[i]); !Iterator_end(&iter); Iterator_next(&iter)) {            
            arr[index++] = Iterator_val(&iter);
        }

        LinkedList_free(&bucket->lists[i]);
    }
}

