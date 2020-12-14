//
// Created by marcin on 14.12.2020.
//

#include <stdlib.h>
#include <stdio.h>
#include "tree_lib.h"

void binaryInsert(Node **parent, direction dir, int data) {
    Node *new_node = (Node *) malloc(sizeof(Node));
    new_node->value = data;
    new_node->parent = *parent;
    new_node->left = NULL;
    new_node->right = NULL;
    if (parent != NULL){
        switch (dir) {
            case LEFT:
                (*parent)->left = new_node;
                break;
            case RIGHT:
                (*parent)->right = new_node;
                break;
            default:
                break;
        }
    }
}

void binaryRemoveNodeWithSubNodes(Node **current){
    printf("Going into node with value %d\n", (*current)->value);

    if ((*current)->left != NULL) binaryRemoveNodeWithSubNodes(&(*current)->left);
    if ((*current)->right != NULL) binaryRemoveNodeWithSubNodes(&(*current)->right);
    if (((*current)->left == NULL) && ((*current)->right == NULL)) {
        Node* old_current = (*current);
        if (old_current->parent != NULL){
            if(old_current->parent->left == old_current){
                //printf("Setting node with value %d left branch to NULL\n", old_current->parent->value);
                old_current->parent->left = NULL;
            }
            if(old_current->parent->right == old_current){
                //printf("Setting node with value %d right branch to NULL\n", old_current->parent->value);
                old_current->parent->right = NULL;
            }
        }
        printf("Freeing node with value %d\n", old_current->value);
        free(old_current);
    }
}

