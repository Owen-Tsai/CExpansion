/*
 * Stack source
 * Stack has a head node, containing stack length as its data
 *
 * CExpansion MIT Licensed
 * Author: Owen Tsai
 */

#include "Stack.h"

Status InitStack(Stack *S) {
    (*S).base = (*S).top = (Ptr) malloc(sizeof(Node));

    if(!(*S).base) {
        exit(OVERFLOW);
    }

    (*S).base->next = NULL;
    (*S).base->data = 0;

    return OK;
}

Status ClearStack(Stack *S) {
    if((*S).base->data == 0) return ERROR;
    Ptr p, q;
    p = (*S).base->next;

    while(p != NULL) {
        q = p->next;
        free(p);
        p = q;
    }

    (*S).top = (*S).base;
    (*S).base->data = 0;
    (*S).base->next = NULL;
    return OK;
}

Status DestroyStack(Stack *S) {
    if((*S).base == NULL) return ERROR;
    Ptr p, q;
    p = (*S).base;

    while(p != NULL) {
        q = p->next;
        free(p);
        p = q;
    }

    return OK;
}

Status IsStackEmpty(Stack S) {
    return S.base == NULL ? TRUE : FALSE;
}

int StackLength(Stack S) {
    return S.base->data;
}

Status GetTopElement(Stack S, element *e) {
    if(S.base == NULL) return ERROR;
    *e = S.top->data;

    return OK;
}

Status Push(Stack *S, element e) {
    Ptr next = (Ptr) malloc(sizeof(Node));
    if(!next) exit(OVERFLOW);

    next->data = e;
    next->next = NULL;

    (*S).top->next = next;
    (*S).top = next;
    (*S).base->data ++;

    return OK;
}

Status Pop(Stack *S, element *e) {
    if((*S).base->data == 0) return ERROR;

    Ptr p = (*S).base->next, q;
    q = p;

    while(p->next != NULL) {
        q = p;
        p = p->next;
    }

    *e = p->data;
    q->next = NULL;
    free(p);

    (*S).top = q;
    (*S).base->data --;
    return OK;
}

Status StackTraverse(Stack S, void(Visit)(element)) {
    if(S.base->data == 0) return ERROR;

    Ptr p = S.base->next;
    while(p != NULL) {
        Visit(p->data);
        p = p->next;
    }

    return OK;
}