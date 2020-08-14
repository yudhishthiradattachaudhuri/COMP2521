
#include "list.h"

bool listIsPalindromic(List l) {
    if (l == NULL || l->first == NULL || l->last == NULL) return true;
	Node lo = l->first;
	Node hi = l->last;
	while ((lo != hi) && (lo->next != hi)) {
	    if (lo->value != hi->value) return false;
        lo = lo->next;
        hi = hi->prev;
	}
	return true;
}

