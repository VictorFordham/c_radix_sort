#ifndef INCLUDE_BUCKET_H_
#define INCLUDE_BUCKET_H_

#include <stdlib.h>
#include "../linked_list/linked_list.h"
#include "../iterator/iterator.h"

typedef struct bucket {
    LinkedList* lists;
} Bucket;

Bucket Bucket_new();
void Bucket_free(Bucket* bucket);

void Bucket_add(Bucket* bucket, int index, int val);
void Bucket_empty(Bucket* bucket, int* arr);

#endif // INCLUDE_BUCKET_H_