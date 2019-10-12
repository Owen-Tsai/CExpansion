/*
 * Sequence List source
 *
 * CExpansion MIT Licensed
 * Author: Owen Tsai
 */

#include "LinkList.h"

Status InitList(LinkList *L) {
    *L = (LinkList) malloc(sizeof(LNode));
    if(!(*L)) {
        exit(OVERFLOW);
    }

    (*L)->data = 0;
    (*L)->next = NULL;
    return OK;
}

Status DestroyList(LinkList *L) {
    LinkList *p;
    p = L;

    while(*p != NULL) {
        *p = (*L)->next;
        free(*L);
        *L = *p;
    }

    return OK;
}

Status ClearList(LinkList *L) {
    if(!(*L)) {
        return ERROR;
    }

    LinkList p, q;
    p = (*L)->next;

    while(p != NULL) {
        q = (p)->next;
        free(p);
        p = q;
    }

    (*L)->next = NULL;
    (*L)->data = 0;
    return OK;
}

Status IsListEmpty(LinkList L) {
    return L->data == 0 ? TRUE : FALSE;
}

Status InsertElement(LinkList *L, int pos, element e) {
    pos = Clamp(1, (*L)->data + 1, pos);
    if(!(*L)) {
        return ERROR;
    }

    LinkList pre;
    pre = (*L);
    for(int j = 0; j < pos - 1; j++) {
        pre = pre->next;
    }

    // Now *pre is pointing the prior element of insertion point
    LinkList cur = (LinkList) malloc(sizeof(LNode));
    if(!cur) {
        exit(OVERFLOW);
    }

    cur->next = pre->next;
    pre->next = cur;
    cur->data = e;

    (*L)->data ++;

    return OK;
}

Status DeleteElement(LinkList *L, int pos, element *e) {
    pos = Clamp(1, (*L)->data, pos);

    LinkList pre;
    pre = (*L);
    for(int j = 0; j < pos - 1; j++) {
        pre = pre->next;
    }

    // Now *pre is pointing the prior element of target
    LinkList cur = pre->next;
    pre->next = cur->next;
    *e = cur->data;
    free(cur);

    (*L)->data --;
    return OK;
}

Status GetElement(LinkList L, int pos, element *e) {
    pos = Clamp(1, L->data, pos);

    LinkList target;
    target = L;
    for(int j = 0; j < pos; j++) {
        target = target->next;
    }

    *e = target->data;
    return OK;
}

int LocateElement(LinkList L, element e, Status(Compare)(element, element)) {
    LinkList target;
    target = L;
    int j = 0;
    for(j; j < L->data; j++) {
        target = target->next;
        if(Compare(target->data, e)) {
            break;
        }
    }

    return j < L->data ? j + 1 : 0;
}

Status GetPrior(LinkList L, element cur, element *e) {
    LinkList target, pre;
    target = L;
    for(int j = 0; j < L->data; j++) {
        pre = target;
        target = target->next;
        if(target->data == cur || pre != L) {
            if(pre != L) {
                *e = pre->data;
                return OK;
            } else {
                return ERROR;
            }
        }
    }

    return ERROR;
}

Status GetNext(LinkList L, element cur, element *e) {
    LinkList target;
    target = L;
    for(int j = 0; j < L->data; j++) {
        target = target->next;
        if(target->data == cur) {
            *e = target->next->data;
            return OK;
        }
    }

    return ERROR;
}

Status ListTraverse(LinkList L, void(Visit)(element)) {
    LinkList p;
    p = L;
    for(int j = 0; j < L->data; j++) {
        p = p->next;
        Visit(p->data);
    }

    return OK;
}