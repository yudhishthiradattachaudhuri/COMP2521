
#include "list.h"

void listReverse(List l) {  
    // do nothing case
    Node curr = l->head;
    if (curr == NULL || curr->next == NULL) return;
	Node prev = NULL; Node next = NULL;
	while (curr != NULL) {
	    next = curr->next;
	    curr->next = prev;
	    // push pointers forward
	    prev = curr;
	    curr = next;
	}
	l->head = prev;
}

