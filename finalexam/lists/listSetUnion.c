
#include "list.h"
#include <stdbool.h>

List ListCopy(List s1);
Node doCopy(Node l);
bool inList(List l, int key);

List listSetUnion(List s1, List s2) {
	// copy first s1 to new list
	List u = ListCopy(s1);
	// add elements from s2 that are not in s1 to new list
	Node curr = s2->head;
	while (curr != NULL) {
	    if (!inList(s1, curr->value)) {
	        Node new = newNode(curr->value);
	        new->next = u->head;
	        u->head = new;
	    }
	    curr = curr->next;
	}
	return u;
}

// copy contents of a list to a new list, return the head of that list
List ListCopy(List s1) {
    List new = newList();
    new->head = doCopy(s1->head);
    return new;
}

Node doCopy(Node n) {
    if (n == NULL) return NULL;
    Node out = newNode(n->value);
    out->next = doCopy(n->next);
    return out;
}

bool inList(List l, int key) {
    Node curr = l->head;
	while (curr != NULL) {
	    if (curr->value == key) return true;
	    curr = curr->next;
	}
	return false;
}





