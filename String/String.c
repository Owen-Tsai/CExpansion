/*
 * String source
 *
 * CExpansion MIT Licensed
 * Author: Owen Tsai
 */

#include "String.h"

Status InitString(String *S) {
    (*S).str = NULL;
    (*S).length = 0;

    return OK;
}

Status StringAssign(String *S, char* chars) {
    (*S).length = strlen(chars);
    if(len == 0) {
        return ERROR;
    }

    int len = (*S).length;

    InitString(S);

    (*S).str = (char*) malloc(len * sizeof(char));
    if(!(*S).str) {
        exit(OVERFLOW);
    }

    for(int i = 0; i < len; i++) {
        (*S).str[i] = chars[i];
    }
    (*S).length = len;

    return OK;
}

Status StringCopy(String *A, String B) {
    if(B.length == 0) {
        return ERROR;
    }

    int len = B.length;

    InitString(A);

    A->str = (char*) malloc(len * sizeof(char));
    if(!(A->str)) {
        exit(OVERFLOW);
    }

    for(int i = 0; i < len; i++) {
        A->str[i] = B.str[i];
    }
    A->length = len;

    return OK;
}

int StringCompare(String A, String B) {
    int lenA = A.length;
    int lenB = B.length;

    for(int i = 0; i < lenA && i < lenB; i++) {
        if(A.str[i] > B.str[i]) {
            return 1;
        }
        if(A.str[i] < B.str[i]) {
            return -1;
        }
    }

    if(lenA > lenB) {
        return 1;
    } else if(lenA < lenB) {
        return -1;
    } else {
        return 0;
    }
}

Status ClearString(String *S) {
    free((*S).str);
    (*S).str= NULL;
    (*S).length = 0;

    return OK;
}

Status ConcatString(String *S, String A, String B) {
    if((*S).str) {
        free((*S).str);
    }

    (*S).str = (char*) malloc((A.length + B.length) * sizeof(char));
    if(!(*S).str) {
        exit(OVERFLOW);
    }

    for(int i = 0; i < A.length; i++) {
        (*S).str[i] = A.str[i];
    }
    for(int i = A.length; i < B.length; i++) {
        (*S).str[i] = B.str[i];
    }

    (*S).length = A.length + B.length;
    return OK;
}

Status SubString(String *sub, String S, int index, int cutLength) {
    if(index < 1 || index > S.length || cutLength < 0 || cutLength > S.length - index + 1) {
        return ERROR;
    }

    if(*sub->str) {
        free(sub->str);
    }

    (*sub).str = (char*) malloc(cutLength * sizeof(char));
    if(!sub->str) {
        exit(OVERFLOW);
    }

    for(int i = index - 1; i < cutLength; i++) {
        sub->str[i] = S.str[i];
    }

    sub->length = cutLength;
    return OK;
}

Status GetNext(String template, int next[]) {
    if(template.length == 0) {
        return ERROR;
    }

    int i = 0, j = -1;
    next[0]  = -1;

    while(i < template.length) {
        if(j == -1 || template.str[i] == template.str[j]) {
            j++;
            i++;
            next[i] = j;
        } else {
            j = next[j];
        }
    }

    return OK;
}

int LocateSubStringKMP(String str, String template, int pos) {
    if(pos <= 0) {
        return -2;
    }
    int nextValues[template.length];
    GetNext(template, nextValues);

    int i = pos - 1, j = 0;
    while(i <= str.length - 1 && j <= template.length - 1) {
        if(j == -1 || str.str[i] == template.str[j]) {
            j++; i++;
        } else {
            j = nextValues[j];
        }
    }

    if(j >= template.length) {
        return i - j + 1;
    } else {
        return 0;
    }
}