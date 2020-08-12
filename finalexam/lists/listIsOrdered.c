
#include "list.h"

bool isAscending(List l);
bool isDescending(List l);

bool listIsOrdered(List l) {
    return isAscending(l) || isDescending(l);
}

bool isAscending(List l) {
    Node curr = l->head;
    if (curr == NULL) return true;
    while (curr->next != NULL) {
        if (curr->value > curr->next->value) return false; 
        curr = curr->next;
    }
    return true;
}

bool isDescending(List l) {
    Node curr = l->head;
    if (curr == NULL) return true;
    while (curr->next != NULL) {
        if (curr->value < curr->next->value) return false; 
        curr = curr->next;
    }
    return true;
}
