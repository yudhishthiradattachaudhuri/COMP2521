
#include <stdlib.h>

#include "tree.h"

int max(int a, int b);

int TreeHeight(Tree t) {
    // height = -1 for empty tree
    if (t == NULL) return -1;
    // if (t == leaf) return 0 not needed, as the 1 and -1 cancel out, returning
    // correct value of 0 for a leaf
    return 1 + max(TreeHeight(t->left), TreeHeight(t->right));
    
}

int max(int a, int b) {
    return (a > b) ? a : b;
}


