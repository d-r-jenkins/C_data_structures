#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H
#include <stdlib.h>

// node in the bst
struct bst_node {
    int value;
    struct bst_node* left;
    struct bst_node* right;
};

// the bst
struct bst {
    int count; // the number of elements in the bst
    struct bst_node* root; // the root element of the tree
};

// initialise bst
struct bst* bst_init(void);

// add element to the bst
int bst_add_node(struct bst* tree, int value);

// check if bst is empty
bool bst_is_empty(struct bst* tree);

// check if node is leaf
bool bst_is_node_leaf(struct bst_node* node);

// find a leaf TODO: maybe make this static?
struct bst_node* bst_find_leaf(struct bst* tree);

// find minimum of tree
struct bst_node* bst_get_min(struct bst* tree);

// find maximum of tree
struct bst_node* bst_get_max(struct bst* tree);

// free all memory associated with bst
void bst_delete_node(struct bst_node* node);

#endif
