#include <stdlib.h>
#include <stdio.h>



typedef int ElementType;
typedef struct TreeNode *BinTree;
typedef struct TreeNode TreeNode;

struct TreeNode {
    ElementType Data;
    BinTree Left;
    BinTree Right;
};

#include "ArrayStack.h"



/**
 * Create Tree
 */
void createTree(BinTree T, ElementType x, ElementType y) {
    T->Left = (BinTree) malloc(sizeof(TreeNode));
    T->Left->Data = x;
    T->Left->Right = NULL;
    T->Left->Left = NULL;

    T->Right = (BinTree) malloc(sizeof(TreeNode));
    T->Right->Data = y;
    T->Right->Left = NULL;
    T->Right->Right = NULL;
}


/**
 * PreOrder, using recursion
 * print: 4 2 1 3 6 5 7
 */
void PreOrderTraversal(BinTree BT) {
    if (BT) {
        printf("%d ", BT->Data);
        PreOrderTraversal(BT->Left);
        PreOrderTraversal(BT->Right);
    }
}
/**
 * PreOrder, using iteration
 * print: 4 2 1 3 6 5 7
 */



/** InOrder, using recursion
 * print: 1 2 3 4 5 6 7
 */
void InOrderTraversal(BinTree BT) {
    if(BT) {
        InOrderTraversal(BT->Left);
        printf("%d ", BT->Data);
        InOrderTraversal(BT->Right);
    }
}
/**
 * InOrder, using iteration
 * print: 1 2 3 4 5 6 7
 */
void IterInOrderTraversal(BinTree BT) {
    BinTree T = BT;
    Stack *S = CreateStack();
    while (T || !IsEmpty(S)) {
        while (T) {
            Push(S, T);
            T = T->Left;
        }
        if (!IsEmpty(S)) {
            T = Pop(S);
            printf("%d ", T->Data);
            T = T->Right;
        }
    }
}



/**
 * PosOrder, using recursion
 * print: 1 3 2 5 7 6 4
 */

void PosOrderTraversal(BinTree BT) {
    if(BT) {
        PosOrderTraversal(BT->Left);
        PreOrderTraversal(BT->Right);
        printf("%d", BT->Data);
    }
}

/**
 * PosOrder, using iteration
 * print: 1 3 2 5 7 6 4
 */



/**
 * Find, using recursion
 */
BinTree Find(ElementType x, BinTree BST) {
    if (!BST)
        return NULL;
    if (x > BST->Data)
        return Find(x, BST->Right);
    else if (x < BST->Data)
        return Find(x, BST->Left);
    else
        return BST;
}

/**
 * Find, using iteration
 */
BinTree IterFind(ElementType x, BinTree BST) {
    while (BST) {
        if (x > BST->Data)
            BST = BST->Right;
        else if (x < BST->Data)
            BST = BST->Left;
        else
            return BST;
    }
    return NULL;
}




int main() {


    BinTree T = (BinTree) malloc(sizeof(TreeNode));
    T->Data = 4;
    createTree(T, 2, 6);
    createTree(T->Left, 1, 3);
    createTree(T->Right, 5, 7);

    //PreOrderTraversal(T);
    //PosOrderGetHeight(T);
    //BinTree position = Find(3, T);
    //printf("%d ", position->Data);

    //InOrderTraversal(T);
    IterInOrderTraversal(T);

    return 0;
}