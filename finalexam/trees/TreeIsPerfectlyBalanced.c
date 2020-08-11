
#include <stdlib.h>

#include "tree.h"

int nNodes(Tree t);

bool TreeIsPerfectlyBalanced(Tree t) {
    // if tree = NULL then it is balanced by default
    // else, need to satisfy abs(nNodes(left)-nNodes(right)) <= 1
    // and rest of tree is perfectly balanced
    return (t == NULL || (TreeIsPerfectlyBalanced(t->left) && TreeIsPerfectlyBalanced(t->right) && 
    abs(nNodes(t->left) - nNodes(t->right) <= 1)));
}

// find number of nodes in a (sub)tree
int nNodes(Tree t) {
    if (t == NULL) return 0;
    return 1 + nNodes(t->left) + nNodes(t->right);
}
