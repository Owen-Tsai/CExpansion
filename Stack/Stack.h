/*
 * Stack
 */

#ifndef CEXPANSION_STACK_H
#define CEXPANSION_STACK_H

#endif //CEXPANSION_STACK_H

#include "../Utls/include.h"

// Data type of elements in the list.
// Default: char
typedef int element;

// Definition for Node
typedef struct Node{
    element data;
    struct Node* next;
} Node;

// Definition for stack pointer
typedef Node *Ptr;

typedef struct {
    Ptr base;
    Ptr top;
} Stack;