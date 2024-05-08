#ifndef LINKED_LIST_WITHOUT_HEAD_NODE_FUNCTION_HUB_H
#define LINKED_LIST_WITHOUT_HEAD_NODE_FUNCTION_HUB_H
using namespace std;

typedef int ElemType;
typedef struct LNode {
    ElemType data; // data
    struct LNode *next; // pointer
} LNode, *LinkList;


// Function1: Initialize a List
void InitList(LinkList &L) {
    L = (LinkList)malloc(sizeof(LNode));
    L->data = NULL; // temporary
    L->next = NULL;
}

LinkList LinkedListCreatHeadInsert1(LinkList &L) {
    L = (LinkList)malloc(sizeof(LNode));
    L->next = NULL;
    L->data = NULL;

    ElemType x;
    scanf("%d", &x);
    L->data = x;

    LNode *p;
    scanf("%d", &x);
    while(x != 9999) {
        p = (LNode *)malloc(sizeof(LNode));
        p->data = x;
        p->next = L->next;
        L->next = p;
        scanf("%d", &x);
    }
    return L;
}
LinkList LinkedListCreatHeadInsert2(LinkList &L) {
    L = (LinkList)malloc(sizeof(LNode));
    L->next = NULL;
    L->data = NULL;

    ElemType x;
    scanf("%d", &x);
    L->data = x;

    LNode *p;
    scanf("%d", &x);
    while(x != 9999) {
        p = (LNode *)malloc(sizeof(LNode));
        p->data = x;
        p->next = L;
        L = p;
        scanf("%d", &x);
    }
    return L;
}
LinkList LinkedListCreatTailInsert(LinkList &L) {
    L = (LinkList)malloc(sizeof(LNode));
    L->next = NULL;
    L->data = NULL;

    ElemType x;
    scanf("%d", &x);
    if (x == 9999) {
        return L;
    }
    L->data = x;

    LNode *s; LNode *p; p = L;
    scanf("%d", &x);
    while (x != 9999) {
        s = (LinkList)malloc(sizeof(LNode));
        s->data = x;
        p->next = s;
        p = s;
        scanf("%d", &x);
    }
    p->next = NULL;
    return L;
}

// Function2: Destroy the List
void DestroyList(LinkList &L) {
    LNode *p;
    while (L != NULL) {
        p = L->next;
        delete L;
        L = p;
    }
}

// Function3: Clear the existing List
void ClearList(LinkList &L) {
    LNode *p;
    while (L->next != NULL) {
        p = L->next;
        L->next = p->next;
        delete p;
    }
    L->data = NULL;
}

// Function4: Return TRUE if the List is empty
bool ListEmpty(LinkList L) {
    if (L->data == NULL && L->next == NULL) {
        return 1;
    } else {
        return 0;
    }
}

// Function5: Return the number of elements
int ListLength(LinkList L) {
    if (L->data == NULL && L->next == NULL) {
        return 0;
    }
    LNode *p;
    p = L;

    int cou = 0;
    while (p != NULL) {
        cou++;
        p = p->next;
    }
    return cou;
}

// Function6: Return the i'th value as e
void GetElem(LinkList L, int i, ElemType &e) {
    LNode *p;
    p = L;
    int cou = 1;
    while (p != NULL && cou < i) {
        p = p->next;
        cou++;
    }
    if (cou == i) {
        e = p->data;
    } else {
        cout << "NULL";
    }
}
void GetElemNode(LinkList L, int i, LinkList &e) {
    LNode *p;
    p = L;
    int cou = 1;
    while (p != NULL && cou < i) {
        p = p->next;
        cou++;
    }
    if (cou == i) {
        e = p;
    } else {
        e = NULL;
    }
}

// Function7: Return the serial number in the list L of the first item whose value is equal to e. Else return 0.
int LocateElem(LinkList L, ElemType e) {
    LNode *p;
    p = L;
    int cou = 1;
    while (p != NULL && p->data != e) {
        p = p->next;
        cou++;
    }
    if (p == NULL) {
        return 0;
    }
    if (p->data == e) {
        return cou;
    } else {
        return 0;
    }
}

// Function8: Return the prior element of cur_e in the list
int PriorElem(LinkList L, ElemType cur_e, ElemType &pre_e) {
    LNode *q;
    q = L;
    while (q->next->data != cur_e) {
        q = q->next;
    }
    pre_e = q->data;
    return pre_e;
}
void PriorElemNode(LinkList L, ElemType cur_e, LinkList &pre_e) {
    LNode *q;
    q = L;
    while (q->next->data != cur_e) {
        q = q->next;
    }
    pre_e = q;
}

// Function9: Return the next element of cur_e in the list
int NextElem(LinkList L, ElemType cur_e, ElemType &next_e) {
    LNode *q;
    q = L;
    while (q->data != cur_e && q != NULL) {
        q = q->next;
    }
    if (q->data == cur_e && q->next == NULL) {
        cout << "NULL";
        return next_e = NULL;
    }
    next_e = q->next->data;
    return next_e;
}

// Function10: Insert element e at position i
bool ListInsert(LinkList &L, ElemType i, ElemType e) {
     while (i == 1) {         
         L->data = e;
         L->next = NULL;      
         return true;
     }
 
    while (i != 1) {
        LNode *p = L;
        for (int cou = 1; cou < i - 1 && p; ++cou) {
            p = p->next;
        }
    
        LNode *q = new LNode;
        q->data = e;
        q->next = p->next;
        p->next = q;
        return true;
    }
    return true;
}

// Function11: Delete element e at location i and return itself
int ListDelete(LinkList &L, ElemType i, ElemType &e) {
    if (i == 1) {
        LNode *p; p = L;
        L = L->next;
        delete p;
        return true;
    }

    LNode *p;
    p = L;
    int cou = 1;
    while (cou < i && p != NULL) {
        cou++;
        p = p->next;
    }
    if (cou != i || p == NULL) {
        return false;
    }

    LNode *q;
    q = L;
    while (q->next != p) {
        q = q->next;
    }

    q->next = p->next;
    e = p->data;
    delete p;
    return e;
}

// Function12: List all of the elements
void ListTraverse(LinkList L) {
    LNode *p;
    p = L;
    cout << p->data << " ";
    while (p->next != NULL) {
        cout << p->next->data << " ";
        p = p->next;
    }
    cout << endl;
}


#endif