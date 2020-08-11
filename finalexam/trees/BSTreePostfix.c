
#include <stdio.h>

#include "BSTree.h"

void BSTreePostfix(BSTree t) {
	if (t != NULL) {
	    // postfix traversal = LRN
	    BSTreePostfix(t->left);
	    BSTreePostfix(t->right);
	    printf(" %d", t->value);
	}
}

