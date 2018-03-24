#ifndef CODEFORTEST_LINKLIST_H
#define CODEFORTEST_LINKLIST_H

typedef int DataType;

typedef struct node {
    DataType data;
    struct node *next;
}ListNode;

typedef ListNode * LinkList;

LinkList Initialize() {
    LinkList head = (LinkList)malloc(sizeof(ListNode));

    head->data = 250;
    head->next = NULL;
    return head;
}

void InsertList(LinkList head, int i, DataType x) {
    if (i < 1) {
        return;
    }

    LinkList p = head;
    int j = 1;
    while (j < i) {
        p = p->next;
        j++;
    }

    LinkList node = (LinkList)malloc(sizeof(ListNode));
    node->data = x;

    node->next = p->next;
    p->next = node;
}

#endif //CODEFORTEST_LINKLIST_H








