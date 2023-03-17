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

void makenull(Queue *q);

int is_empty(Queue q);

void en_queue(ElementType x, Queue *q);

ElementType de_queue(Queue *q);

ElementType front(Queue q);

void print(Queue *q);