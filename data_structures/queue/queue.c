#include <stdio.h>
#include <malloc.h>

typedef int ElementType;
struct Node {
    ElementType data;
    struct Node* next;
};
typedef struct {
    struct Node* front;
    struct Node* rear;
    int size;
}Queue;

void makenull(Queue *q) {
    struct Node * first = (struct Node*)malloc(sizeof(struct Node));
    q->front = first;
    q->rear = first;
    q->size = 0;
}

int is_empty(Queue q) {
    return q.size == 0;
}

void en_queue(ElementType x, Queue *q) {
    struct Node* p = (struct Node*) malloc(sizeof(struct Node));
    p->data = x;
    q->rear->next = p;
    p->next = NULL;
    q->rear = p;
    q->size += 1;
}

ElementType de_queue(Queue *q) {
    if (!is_empty(*q)){
        struct Node* t = q->front->next;
        q->front->next = t->next;
        q->size -= 1;
        ElementType x = t->data;
        free(t);
        return x;
    }
    return -10000;
}

ElementType front(Queue q) {
    if (!is_empty(q)) {
        return q.front->next->data;
    }
    return -10000;
}

void print(Queue *q) {
    while (!is_empty(*q)) {
        printf("%d ", de_queue(q));
    }
    printf("\n");
}

