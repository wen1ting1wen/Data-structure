//
// Created by wen on 2018/3/24.
//

#ifndef CODEFORTEST_ARRAYSTACK_H
#define CODEFORTEST_ARRAYSTACK_H

typedef TreeNode* Element ;

#define MaxSize 100
typedef struct {
    Element Data[MaxSize];
    int Top;
} Stack;

void Push(Stack* PtrS, Element item) {
    if (PtrS->Top == MaxSize - 1) {
        printf("Stack is flow !");
        return;
    } else {
        PtrS->Data[++(PtrS->Top)] = item;
        return;
    }
}

Element Pop(Stack* PtrS) {
    if (PtrS->Top == -1) {
        printf("Stack is empty!");
        exit(0);
    } else {
        return (PtrS->Data[(PtrS->Top)--]);
    }
}

Stack* CreateStack() {
    Stack* PtrS = (Stack *) malloc(sizeof(Stack));
    PtrS->Top = -1;

    return PtrS;
}

int IsEmpty(Stack* PtrS) {
    if (PtrS->Top == -1) {
        return 1;
    }
    return 0;
}



#endif //CODEFORTEST_ARRAYSTACK_H
