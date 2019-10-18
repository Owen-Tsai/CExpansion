/*
 * Queue source
 *
 * CExpansion MIT Licensed
 * Author: Owen Tsai
 */

#include "Queue.h"

Status InitQueue(Queue *Q) {
    (*Q).front = (*Q).rear = (Ptr) malloc(sizeof(Node));
    if(!(*Q).front) {
        exit(OVERFLOW);
    }

    (*Q).front->data = 0;
    (*Q).front->next = NULL;

    return OK;
}

Status ClearQueue(Queue *Q) {
    if((*Q).front->data == 0) {
        return ERROR;
    }

    Ptr p = (*Q).front->next, q = p;

    while(p != NULL) {
        q = p->next;
        free(p);
        p = q;
    }

    (*Q).rear = (*Q).front;
    (*Q).front->data = 0;
    (*Q).front->next = NULL;

    return OK;
}

Status EnQueue(Queue *Q, element e) {
    Ptr next = (Ptr) malloc(sizeof(Node));
    if(!next) {
        exit(OVERFLOW);
    }

    next->data = e;
    next->next = NULL;

    (*Q).rear->next = next;
    (*Q).rear = next;
    (*Q).front->data ++;

    return OK;
}

Status DeQueue(Queue *Q, element *e) {
    if((*Q).front->data == 0) return ERROR;

    Ptr p = (*Q).front->next;
    *e = p->data;
    (*Q).front->next = p->next;

    if((*Q).rear == p) {
        (*Q).rear = (*Q).front;
    }

    free(p);
    (*Q).front->data --;

    return OK;
}

Status IsQueueEmpty(Queue Q) {
    return Q.front->data == 0 ? TRUE : FALSE;
}

Status QueueLength(Queue Q) {
    return Q.front->data;
}

Status GetHead(Queue Q, element *e) {
    if(Q.front->data == 0) return ERROR;

    *e = Q.front->next->data;
    return OK;
}