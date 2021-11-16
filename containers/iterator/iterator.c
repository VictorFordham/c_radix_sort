#include "iterator.h"

int Iterator_end(Iterator* iter) {
    return iter->end(iter);
}

void Iterator_next(Iterator* iter) {
    iter->next(iter);
}

int Iterator_val(Iterator* iter) {
    return iter->val(iter);
}