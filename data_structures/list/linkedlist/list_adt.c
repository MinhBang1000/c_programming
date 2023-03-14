#include<stdio.h>
#include<malloc.h>

typedef int ElementType;
struct Node {
    ElementType data;
    struct Node* next;
};
// Position
typedef struct Node* Iterator;
// List 
typedef struct {
    Iterator head, tail;
    int size;
}List;

void makenull(List *l) {
    Iterator first = (Iterator) malloc(sizeof(struct Node));
    l->head = first;
    l->tail = first;
    l->size = 0;
}

Iterator begin(List l) {
    return l.head;
}

Iterator end(List l) {
    return l.tail;
}

Iterator next(Iterator p, List l) {
    return p->next;
}

void insert_first(ElementType x, List *l) {
    Iterator newNode = (Iterator) malloc(sizeof(struct Node));
    newNode->data = x;
    if (l->head == l->tail) {
        l->tail = newNode;
        newNode->next = NULL;
    }else {
        newNode->next = l->head->next;
    }
    l->head->next = newNode;
    l->size+=1;
}

void print(struct Node* p) {
    while (p->next!= NULL) {
        printf("%d ", p->next->data);
        p = p->next;
    }
    printf("\n");
}

ElementType get_at(Iterator p, List l) {
    if (p->next == NULL) {
        return -10000;
    }
    return p->next->data;
}

ElementType set_at(ElementType x, Iterator p, List *l) {
    if (p->next == NULL) {
        printf("Invalid position.\n");
        return -10000;
    }
    p->next->data = x;
    return p->next->data;
}

ElementType insert_at(ElementType x, Iterator p, List *l) {
    Iterator newNode = (Iterator) malloc(sizeof(struct Node));
    newNode->data = x;
    if (l->head == l->tail) {
        l->head->next = newNode;
        l->tail = newNode;
        newNode->next = NULL;    
    }else{
        if (p == l->tail) {
            l->tail = newNode;
        }
        newNode->next = p->next;
        p->next = newNode;
    }
    l->size += 1;
    return newNode->data; 
}

ElementType delete_at(Iterator p, List *l) {
    if (l->head == l->tail || p->next == NULL) {
        return -10000;
    }
    ElementType data = p->next->data;
    Iterator tmp = p->next;
    p->next = tmp->next;
    free(tmp);
    if (p->next == NULL) {
        l->tail = p;
    }    
    l->size -= 1;
    return data;
}

ElementType delete_first(List *l) {
    Iterator p = l->head;
    if (l->head == l->tail) {
        return -10000;
    }
    ElementType data = p->next->data;
    Iterator tmp = p->next;
    p->next = tmp->next;
    if (p->next == NULL) {
        l->tail = p;
    }
    free(tmp);
    l->size -= 1;
    return data;
}

void print_list(List l) {
    Iterator p = l.head;
    while (p->next != NULL) {
        printf("%d ", p->next->data);
        p = p->next;
    }
    printf("\n");
}

double get_average(List l) {
    if (l.head == l.tail) {
        return -10000;
    }
    Iterator p = l.head;
    double sum = 0;
    while (p->next!=NULL) {
        sum += p->next->data;
        p = p->next;
    }
    return sum/(double) l.size;
}

int main() {
    List L;
    Iterator p;
    ElementType x;
    makenull(&L);
    p = begin(L);
    insert_at(10, p, &L);
    p = next(p, L);
    insert_at(20, p, &L);
    p = next(p, L);
    insert_at(100, p, &L);
    p = next(p, L);
    insert_at(40, p, &L);
    print(L.head);
    x = delete_first(&L);
    printf("%d\n", x);
    return 0;
}