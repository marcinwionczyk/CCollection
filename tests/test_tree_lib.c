//
// Created by marcin on 14.12.2020.
//

#include <stdlib.h>
#include "../libs/tree_lib.h"
#include "../unity/unity.h"

void test_try_insert_and_remove(void){
    Node *master = (Node *) calloc(1, sizeof(Node));
    binaryInsert(&master, LEFT, 1);
    binaryInsert(&master, RIGHT, 2);
    binaryInsert(&master->left, LEFT, 3);
    binaryInsert(&master->left, RIGHT, 4);
    binaryInsert(&master->right, RIGHT, 5);
    binaryRemoveNodeWithSubNodes(&master->right);
}