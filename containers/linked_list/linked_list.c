#include "linked_list.h"

LinkedList LinkedList_new() {
    LinkedList out = {
        .head=NULL,
        .len=0
    };

    return out;
}

void LinkedList_free_helper(LinkedListNode* node) {
    if (node->next != NULL)
        LinkedList_free_helper(node->next);
    
    free(node);
}

void LinkedList_free(LinkedList* list) {
    if (list->len > 0)
        LinkedList_free_helper(list->head);

    list->head = NULL;
    list->tail = NULL;
    list->len = 0;
}

int LinkedListIterator_end(Iterator* iter) {
    return ((LinkedListNode*)iter->data) == NULL;
}

void LinkedListIterator_next(Iterator* iter) {
    iter->data = (void *) ((LinkedListNode*)iter->data)->next;
}

int LinkedListIterator_val(Iterator* iter) {
    return ((LinkedListNode*)iter->data)->val;
}

Iterator LinkedList_iter(LinkedList* list) {
    Iterator out = {
        .end=LinkedListIterator_end,
        .next=LinkedListIterator_next,
        .val=LinkedListIterator_val,
        .data=(void *) list->head,
    };

    return out;
}

void LinkedList_add(LinkedList* list, int val) {
    LinkedListNode* node = malloc(sizeof(LinkedListNode));
    node->next = NULL;
    node->val = val;

    if (list->head == NULL) {
        list->head = node;
        list->tail = node;
        return;
    }

    list->tail->next = node;
    list->tail = node;
}