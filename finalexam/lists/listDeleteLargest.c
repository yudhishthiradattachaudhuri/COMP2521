
#include "list.h"

int listDeleteLargest(List l) {
	int max = -1;
	Node curr = l->head; Node prev = NULL;
	// find the max value
	while (curr != NULL) {
	    if (curr->value > max) max = curr->value;
	    curr = curr->next;
	}
	// delete the first instance
	curr = l->head;
	while (curr != NULL) {
        if (curr->value == max) {
            if (curr == l->head) {
                l->head = curr->next;
            } else {
                prev->next = curr->next;
            }
            free(curr);
            break;
        }
        prev = curr;
        curr = curr->next;
	}
	return max;
}

