
#include "tree.h"

#include <stdlib.h>

Tree newNode(int val);

Tree TreeCopy(Tree t, int depth) {
	if (depth < 0 || t == NULL) return NULL;
	Tree new = malloc(sizeof(*new));
	new->value = t->value;
	new->left = TreeCopy(t->left, depth - 1);
    new->right = TreeCopy(t->right, depth - 1);
    return new;
}


