
#include "BSTree.h"

#include <stdlib.h>

BSTree BSTreeGetSmallest(BSTree t) {
   	// keep going left until cannot go further to get smallest
	if (t == NULL) return NULL;
	else if (t->left == NULL) return t;
	return BSTreeGetSmallest(t->left);
}

