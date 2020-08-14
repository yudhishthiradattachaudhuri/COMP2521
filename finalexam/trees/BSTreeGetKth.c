
#include <stdlib.h>

#include "BSTree.h"

void doGetKth(BSTree t, int k, int *count, int *kth);

int BSTreeGetKth(BSTree t, int k) {
	int kth; int count = 0;
	doGetKth(t, k, &count, &kth);
	return kth;
}

// use LNR traversal to get values in ascending order
void doGetKth(BSTree t, int k, int *count, int *kth) {
    if (t == NULL) return;
    // traverse left subtree
    doGetKth(t->left, k, count, kth);
    // if found kth value
    if (*count == k) {
        *kth = t->value;
    }
    // increment the counter index at the parent node
    *count += 1;
    // traverse right subtree
    doGetKth(t->right, k, count, kth);
}

