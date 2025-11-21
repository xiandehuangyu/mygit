#include<stdio.h>
#include<stdlib.h>
#ifndef _LIST_H

struct Node;
typedef struct Node *PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;

List MakeEmpty(List L);
int IsEmpty(List L);
int IsLast(Position P, List L);
Position Find(int e, List L);
void Delete(int e, List L);
Position FindPrevious(int e, List L);
void Insert(int e, List L, Position P);
void DeleteList(List L);
Position Header(List L);
Position First(List L);
Position Advance(Position P);
int Retrieve(Position P);

#endif

struct Node {
    int element;
    Position next;
};

List MakeEmpty(List L) {
    if(L != NULL)
        DeleteList(L);
    L = (List)malloc(sizeof(struct Node));
    L->next = NULL;
    return L;
}

int IsEmpty(List L) {
    return L->next == NULL;
}

int IsLast(Position P, List L) {
    return P->next == NULL;
}

Position Find(int e, List L) {
    Position P = L->next;
    while (P != NULL && P->element != e) {
        P = P->next;
    }
    return P;
}

void Delete(int e, List L) {
    Position P = FindPrevious(e, L);
    if (!IsLast(P, L)) {
        Position Temp = P->next;
        P->next = Temp->next;
        free(Temp);
    }
}

Position FindPrevious(int e, List L) {
    Position P = L;
    while (P->next != NULL && P->next->element != e) {
        P = P->next;
    }
    return P;
}

void Insert(int e, List L, Position P) {
    Position NewNode = (Position)malloc(sizeof(struct Node));
    NewNode->element = e;
    NewNode->next = P->next;
    P->next = NewNode;
}

void DeleteList(List L) {
    Position P = L->next;
    L->next = NULL;
    while (P != NULL) {
        Position Temp = P->next;
        free(P);
        P = Temp;
    }
}

Position Header(List L) {
    return L;
}

Position First(List L) {
    return L->next;
}

Position Advance(Position P) {
    return P->next;
}

int Retrieve(Position P) {
    return P->element;
}

int main(void){
    List L = MakeEmpty(NULL);
    Position P;
    int val;
    Insert(10, L, Header(L));
    Insert(30, L, Find(10, L));
    printf("3. 遍历链表：");
    P = First(L);
    while (P != NULL) {
        printf("%d ", Retrieve(P));
        P = Advance(P);
    }
    printf("\n\n");
    return 0;
}