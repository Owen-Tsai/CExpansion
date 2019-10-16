//
// Created by Owen Tsai on 2019/10/16.
//

#ifndef CEXPANSION_STACK_H
#define CEXPANSION_STACK_H

#endif //CEXPANSION_STACK_H

#include "../Utls/include.h"

// Data type of elements in the list.
// Default: char
typedef char element;

// Definition for Node
typedef struct Node{
    element data;
    struct Node* next;
} Node;

// Definition for Stack
typedef Node* Stack;