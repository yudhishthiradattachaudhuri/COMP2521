
#include <stdlib.h>

#include "BSTree.h"

int BSTreeNodeDepth(BSTree t, int key) {
    if (t == NULL) return -1;
    if (t->value == key) return 0;
    int leftDepth = BSTreeNodeDepth(t->left, key);
    // found in left subtree
    if (leftDepth != -1) {
        // add height from left subtree + 1 for current node
        return 1 + leftDepth;
    // not found, try right subtree
    } else {
        // found in right subtree
        int rightDepth = BSTreeNodeDepth(t->right, key);
        if (rightDepth != -1) return 1 + rightDepth;
        // not found anywhere, return -1
        else return -1;
    }
}


