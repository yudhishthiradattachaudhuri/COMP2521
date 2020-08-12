
#include "list.h"

void reverseDLList(List l) {
	Node curr = l->first; Node tmp;
	// default case
	if (curr == NULL || curr->next == NULL) return;
	l->last = curr;
	while (curr != NULL) {
	    // swap prev and next pointers
	    tmp = curr->prev;
	    curr->prev = curr->next;
	    curr->next = tmp;
	    // iterate to "next" by using prev as already reversed
	    curr = curr->prev;
	}
	// access the final node of original by using tmp->prev after prev and next
	// has already been swapped, tmp is the 2nd last node in list after the
	// last iteration
	l->first = tmp->prev;
}

