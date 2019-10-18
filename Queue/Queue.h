/*
 * Queue
 */

#ifndef CEXPANSION_QUEUE_H
#define CEXPANSION_QUEUE_H

#endif //CEXPANSION_QUEUE_H

#include "../Utls/include.h"

typedef int element;

typedef struct Node {
    element data;
    struct Node* next;
} Node;

typedef Node *Ptr;

typedef struct {
    Ptr front;
    Ptr rear;
} Queue;