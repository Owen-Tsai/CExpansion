/*
 * Link List
 */

#ifndef CEXPANSION_LINKLIST_H
#define CEXPANSION_LINKLIST_H

#endif //CEXPANSION_LINKLIST_H

#include "../Utls/include.h"
#include "../Utls/Status.h"
#include "../Utls/MathHelper.c"

// Data type of elements in the list.
// Default: int
typedef int element;

// Definition of Link List Node
typedef struct LNode{
    element data;
    struct LNode* next;
}LNode;

// Definition of Link List
typedef LNode* LinkList;

Status InitList(LinkList *L);

Status DestroyList(LinkList *L);

Status ClearList(LinkList *L);

Status IsListEmpty(LinkList L);

Status GetElement(LinkList L, int pos, element *e);

int LocateElement(LinkList L, element e, Status(Compare)(element, element));

Status GetPrior(LinkList S, element cur, element *prior);

Status GetNext(LinkList S, element cur, element *next);

Status InsertElement(LinkList *L, int pos, element e);

Status DeleteElement(LinkList *L, int pos, element *e);

Status ListTraverse(LinkList L, void(Visit)(element));