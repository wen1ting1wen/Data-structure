#ifndef CODEFORTEST_ARRAYLIST_H
#define CODEFORTEST_ARRAYLIST_H

#define ListSize 100
typedef int DataType;

typedef struct {
    DataType data[ListSize];
    int length;
} SeqList;


SeqList *MakeEmpty() {
    SeqList *ptrl;
    ptrl = (SeqList*)malloc(sizeof(SeqList));
    ptrl->length = 0;
    return ptrl;
}

void InsertList(SeqList *L, int i, DataType x) {
    int j;
    if (i < 1 || i > L->length + 1) {
        printf("position error");
    }

    if (L->length >= ListSize) {
        printf("overflow");
        return;
    }

    for (j = L->length-1; j >= i-1; j--) {
        L->data[j+1] = L->data[j];
    }

    L->data[i-1] = x;
    L->length++;
}

DataType DeleteList(SeqList *L, int i) {
    int j;
    DataType x;
    if (i < 1 || i > L->length) {
        printf("position error");
        exit(0);
    }

    x = L->data[i-1];
    for (j = i; j <= L->length; j++) {
        L->data[j-1] = L->data[j];
    }
    L->length--;
    return x;
}

void Converts(SeqList *L) {
    DataType temp;
    int i, k;
    k = L->length / 2;
    for (i = 0; i < k; i++) {
        temp = L->data[i];
        L->data[i] = L->data[L->length-i-1];
        L->data[L->length-i-1] = temp;
    }
}

int Max(SeqList *L) {
    if (L->length == 0) {
        exit(0);
    }

    int position = 0;

    for (int i = 0; i < L->length; i++) {
        if (L->data[position] < L->data[i]) {
            position = i;
        }
    }

    return position;
}

#endif //CODEFORTEST_ARRAYLIST_H

