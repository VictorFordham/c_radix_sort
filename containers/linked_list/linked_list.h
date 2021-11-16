#ifndef INCLUDE_LINKED_LIST_H_
#define INCLUDE_LINKED_LIST_H_

#include <stdlib.h>
#include "../iterator/iterator.h"

typedef struct linked_list {
    struct linked_list_node* head;
    struct linked_list_node* tail;
    int len;
} LinkedList;

typedef struct linked_list_node {
    struct linked_list_node* next;
    int val;
} LinkedListNode;

LinkedList LinkedList_new();
void LinkedList_free(LinkedList* list);

Iterator LinkedList_iter(LinkedList* list);

void LinkedList_add(LinkedList* list, int val);

#endif // INCLUDE_LINKED_LIST_H_