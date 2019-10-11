/*
 * Sequence List
 */

#ifndef CEXPANSION_SEQUENCELIST_H
#define CEXPANSION_SEQUENCELIST_H

#endif //CEXPANSION_SEQUENCELIST_H

#include "../Utls/include.h"
#include "../Utls/Status.h"
#include "../Utls/MathHelper.c"

// Initial allocation of space
#define LIST_INIT_SIZE 100

// Increment of space each time list needs reallocation
#define LIST_INCREMENT 10

// Data type of elements in the list.
// Default: int
typedef int element;

// Definition for SequenceList
typedef struct {
    element *elem;
    int length;
    int listSize;
} SqList;

Status InitList(SqList *S);

Status DestroyList(SqList *S);

Status ClearList(SqList *S);

Status IsListEmpty(SqList S);

Status GetElement(SqList S, int pos, element *e);

int LocateElement(SqList S, element e, Status(Compare)(element, element));

Status GetPrior(SqList S, element cur, element *prior);

Status GetNext(SqList S, element cur, element *next);

Status InsertElement(SqList *S, int pos, element e);

Status DeleteElement(SqList *S, int pos, element *e);

Status ListTraverse(SqList S, void(Visit)(element));