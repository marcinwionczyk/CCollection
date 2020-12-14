//
// Created by marcin on 14.12.2020.
//

#ifndef C_TEST_TREE_LIB_H
#define C_TEST_TREE_LIB_H

typedef enum dir {
    LEFT, RIGHT
} direction;

typedef struct Node {
    int value;
    struct Node *parent;
    struct Node *left;
    struct Node *right;
} Node;

void binaryInsert(Node **parent, direction dir, int data);
void binaryRemoveNodeWithSubNodes(Node **current);
Node *search(int data);


#endif //C_TEST_TREE_LIB_H
