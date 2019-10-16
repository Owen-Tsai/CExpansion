/*
 * Stack source
 *
 * CExpansion MIT Licensed
 * Author: Owen Tsai
 */

#include "Stack.h"

Status InitStack(Stack *S) {
    (*S) = (Stack) malloc(sizeof(Node));
    if(!(*S)) {
        exit(OVERFLOW);
    }

    (*S)->data = 0;
    (*S)->next = NULL;

    return OK;
}

Status ClearStack(Stack *S) {
    if(!(*S)) return ERROR;
    Stack p, q;
    p = (*S)->next;

    while(p != NULL) {
        q = p->next;
        free(p);
        p = q;
    }

    (*S)->data = 0;
    (*S)->next = NULL;
    return OK;
}

Status DestroyStack(Stack *S) {
    if(!(*S)) return ERROR;
    Stack p, q;
    p = (*S);

    while(p != NULL) {
        q = p->next;
        free(p);
        p = q;
    }

    return OK;
}

Status IsStackEmpty(Stack S) {
    return S->data == 0 ? TRUE : FALSE;
}

int StackLength(Stack S) {
    return S->data;
}

Status GetTopElement(Stack S, element *e) {
    if(!S || S->data == 0) return ERROR;
    Stack p = S;

    for(int i = 0; i < S->data; i++) {
        p = p->next;
    }

    *e = p->data;
    return OK;
}

Status Push(Stack *S, element e) {
    Stack p = (*S);

    for(int i = 0; i < (*S)->data; i++) {
        p = p->next;
    }

    // Now p is pointing prior element of insertion point
    p->next = (Stack) malloc(sizeof(Node));
    if(!(p->next)) {
        exit(OVERFLOW);
    }
    p->next->data = e;
    p->next->next = NULL;

    return OK;
}

Status Pop(Stack *S, element *e) {
    Stack p = (*S);

    for(int i = 0; i < (*S)->data - 1; i++) {
        p = p->next;
    }

    *e = p->next->data;
    p->next = NULL;
    free(p->next);

    return OK;
}

Status StackTraverse(Stack S, void(Visit)(element)) {
    if(!S) return ERROR;

    Stack p = S->next;
    while(p != NULL) {
        Visit(p->data);
        p = p->next;
    }

    return OK;
}