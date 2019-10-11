/*
 * Sequence List source
 *
 * CExpansion MIT Licensed
 * Author: Owen Tsai
 */

#include "SequenceList.h"

Status InitList(SqList *S) {
    S->elem = (element * ) malloc (LIST_INIT_SIZE * sizeof(element));
    if(!S->elem) {
        return OVERFLOW;
    }

    S->length = 0;
    S->listSize = LIST_INIT_SIZE;
    return OK;
}

Status DestroyList(SqList *S) {
    S->elem = NULL;
    free(S->elem);

    S->length = 0;
    S->listSize = 0;
    return OK;
}

Status ClearList(SqList *S) {
    S->length = 0;
    return OK;
}

Status IsListEmpty(SqList S) {
    return S.length == 0 ? TRUE : FALSE;
}

int LocateElement(SqList S, element e, Status(Compare)(element, element)) {
    int i = 0;
    for(i; i < S.length; i++) {
        if(Compare(e, S.elem[i])) {
            break;
        }
    }

    return i < S.length ? i + 1 : 0;
}

Status GetElement(SqList S, int pos, element *e) {
    if(pos < 1 || pos > S.length) {
        return ERROR;
    }

    *e = S.elem[pos - 1];
    return OK;
}

Status GetPrior(SqList S, element cur, element *prior) {
    for(int i = 0; i < S.length; i++) {
        if(S.elem[i] == cur) {
            if(i != 0) {
                *prior = S.elem[i-1];
                return OK;
            }
        }
    }

    return 0;
}

Status GetNext(SqList S, element cur, element *next) {
    for(int i = 0; i < S.length; i++) {
        if(S.elem[i] == cur) {
            if(i != S.length - 1) {
                *next = S.elem[i + 1];
                return OK;
            }
        }
    }

    return 0;
}

Status InsertElement(SqList *S, int pos, element e) {
    // Constrain index between valid section
    pos = Clamp(1, S->length + 1, pos);

    if(S->length >= S->listSize) {
        element *newBase;
        newBase = (element *) realloc(S->elem, S->listSize + LIST_INCREMENT * sizeof(element));

        if(!newBase) {
            exit(OVERFLOW);
        }

        S->elem = newBase;
        S->listSize += LIST_INCREMENT;
    }

    for(int i = S->length; i > pos - 1; i--) {
        S->elem[i] = S->elem[i - 1];
    }

    S->elem[pos - 1] = e;
    S->length ++;

    return OK;
}

Status DeleteElement(SqList *S, int pos, element *e) {
    // Constrain index between valid section
    pos = Clamp(1, S->length, pos);

    *e = S->elem[pos];

    for(int i = pos - 1; i < S->length - 1; i++) {
        S->elem[i] = S->elem[i + 1];
    }

    S->length --;

    return OK;
}

Status ListTraverse(SqList S, void(Visit)(element)) {
    for(int i = 0; i < S.length; i++) {
        Visit(S.elem[i]);
    }

    return OK;
}