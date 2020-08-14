
#include "list.h"
#include <stdbool.h>

bool inList(List l, int key);

List listSetDifference(List l1, List l2) {
	// double nested loop to add common elements
	List i = newList();
	Node curr1 = l2->head;
	while (curr1 != NULL) {
	    Node curr2 = l1->head;
	    while (curr2 != NULL) {
	        if (!inList(l2, curr2->value) && !inList(i, curr2->value)) {
	            Node new = newNode(curr2->value);
	            new->next = i->head;
	            i->head = new;
	        }
	        curr2 = curr2->next;
	    }
	    curr1 = curr1->next;
	}
	return i;
}

// check if a value is in a list
bool inList(List l, int key) {
    Node curr = l->head;
	while (curr != NULL) {
	    if (curr->value == key) return true;
	    curr = curr->next;
	}
	return false;
}
