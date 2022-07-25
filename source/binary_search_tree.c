#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <binary_search_tree.h>

// initialise bst
struct bst* bst_init(void){
    struct bst* tree = calloc(1, sizeof(struct bst));
    if (tree == NULL){
        printf("Failed to calloc tree.\n");
        exit(EXIT_FAILURE);
    }

    tree->count = 0;
    tree->root = NULL;

    return tree;
}

// add element to the bst
int bst_add_node(struct bst* tree, int value){
    struct bst_node* new_node = calloc(1, sizeof(struct bst_node));
    if (new_node == NULL){
        printf("Failed to calloc new node.\n");
        exit(EXIT_FAILURE);
    }

    new_node->value = value;
    new_node->left = NULL;
    new_node->right = NULL;

    struct bst_node* target = tree->root;
    struct bst_node* old_target = NULL;
    while (target != NULL){
        old_target = target;
        if (target->value > new_node->value){
            target = target->left;
        }
        else if (target->value < new_node->value){
            target = target->right;
        }
        else{
            printf("Duplicate key.");
            return 1;
        }
    }

    if (old_target == NULL){
        tree->root = new_node;
    }
    else if (old_target->value > new_node->value){
        old_target->left = new_node;
    }
    else if (old_target->value < new_node->value){
        old_target->right = new_node;
    }
    else{
        // TODO write error catching code here
        printf("This case should never occur");
        exit(EXIT_FAILURE);
    }
    tree->count++;

    return tree->count;
}

// check if bst is empty
bool bst_is_empty(struct bst* tree){
    if (tree->count == 0){
        return true;
    }
    else{
        return false;
    }
}

bool bst_is_node_leaf(struct bst_node* node){
    if (node->left == NULL && node->right == NULL){
        return true;
    }
    else{
        return false;
    }
}

// find a leaf TODO: maybe make this static?
struct bst_node* bst_find_leaf(struct bst* tree){
    struct bst_node* test_leaf = tree->root;

    while(!bst_is_node_leaf(test_leaf)){
        if (test_leaf->left == NULL){
            test_leaf = test_leaf->right;
        }
        else{
            test_leaf = test_leaf->left;
        }
    }

    return test_leaf;
}

// find minimum of tree
struct bst_node* bst_get_min(struct bst* tree){
    struct bst_node* minimum = tree->root;

    while(minimum->left != NULL){
        minimum = minimum->left;
    }

    return minimum;
}

// find maximum of tree
struct bst_node* bst_get_max(struct bst* tree){
    struct bst_node* maximum = tree->root;

    while(maximum->right != NULL){
        maximum = maximum->right;
    }

    return maximum;
}

void bst_delete_node(struct bst_node* node){
    if (node->right != NULL){
        bst_delete_node(node->right);
    }
    if (node->left != NULL){
        bst_delete_node(node->left);
    }

    free(node);
}
