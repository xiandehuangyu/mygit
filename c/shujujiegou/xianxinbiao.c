#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100
typedef int ElemType;

typedef struct {
    int length;
    ElemType data[MAXSIZE];
} SqList;

void InitList(SqList *L) {
    L->length = 0;
}

void DestroyList(SqList *L) {

}

int ListEmpty(SqList *L) {
    return L->length == 0;
}

int GetLength(SqList *L) {
    return L->length;
}

int GetElem(SqList *L, int i) {
    if (i < 0 || i >= L->length) {
        printf("下标越界！\n");
        return -1;
    }
    return L->data[i];
}

void Insert(ElemType x, SqList *L, int i) {
    if (i < 0 || i > L->length) {
        printf("下标越界！\n");
        return;
    }
    if (L->length >= MAXSIZE) {
        printf("顺序表已满！\n");
        return;
    }
    for (int j = L->length - 1; j >= i; j--) {
        L->data[j + 1] = L->data[j];
    }
    L->data[i] = x;
    L->length++;
}

void Delete(int i, SqList *L) {
    if (i < 0 || i >= L->length) {
        printf("下标越界！\n");
        return;
    }
    for (int j = i; j < L->length - 1; j++) {
        L->data[j] = L->data[j + 1];
    }
    L->length--;
}

void DeleteElem(ElemType x, SqList *L) {
    for (int i = 0; i < L->length; i++) {
        if (L->data[i] == x) {
            Delete(i, L);
            i--;
        }
    }
}

void append(SqList *L, ElemType x) {
    if (L->length >= MAXSIZE) {
        printf("顺序表已满！\n");
        return;
    }
    L->data[L->length] = x;
    L->length++;
}
void printList(SqList *L) {
    for (int i = 0; i < L->length; i++) {
        printf("%d ", L->data[i]);
    }
    printf("\n");
}

int main(void){
    SqList L;
    InitList(&L);
    append(&L, 10);
    append(&L, 20);
    append(&L, 30);
    append(&L, 40);
    printList(&L);
    Delete(1, &L);
    printList(&L);
    Insert(15, &L, 2);
    printList(&L);
    DeleteElem(20, &L);
    printList(&L);
    DestroyList(&L);
    return 0;
}