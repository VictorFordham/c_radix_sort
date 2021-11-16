#ifndef INCLUDE_ITERATOR_H_
#define INCLUDE_ITERATOR_H_

typedef struct iterator {
    int (*end)(struct iterator*);
    void (*next)(struct iterator*);
    int (*val)(struct iterator*);
    void* data;
} Iterator;

int Iterator_end(Iterator* iter);
void Iterator_next(Iterator* iter);
int Iterator_val(Iterator* iter);

#endif // INCLUDE_ITERATOR_H_