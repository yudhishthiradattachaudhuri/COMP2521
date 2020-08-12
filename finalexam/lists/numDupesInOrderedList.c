
#include "list.h"

int numDupesInOrderedList(List l) {
	int curVal = -1;
	Node curr = l->head;
	int count = 0;
	while (curr != NULL) {
	    if (curVal == curr->value) count++;
	    else curVal = curr->value;
	    curr = curr->next;
	}
	return count;
}

