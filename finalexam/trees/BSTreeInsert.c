
#include <stdio.h>
#include <stdlib.h>

#include "BSTree.h"

BSTree newNode(int val);

BSTree BSTreeInsert(BSTree t, int val) {
	if (t == NULL) return newNode(val);
	else if (val < t->value) t->left = BSTreeInsert(t->left, val);
	else if (val > t->value) t->right = BSTreeInsert(t->right, val);
	return t;
}

BSTree newNode(int val) {
    BSTree new = malloc(sizeof(*new));
    new->left = NULL; new->right = NULL;
    new->value = val;
    return new;
}
