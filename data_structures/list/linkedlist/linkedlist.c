#include<stdio.h>
#include<malloc.h>

typedef int ElementType;
struct Node {
    ElementType data;
    struct Node *next;
};
struct Node* header;

struct Node* new_node() {
    struct Node *p = (struct Node*) malloc(sizeof(struct Node));
    p->next = NULL;
    return p;
}

void insert_node(ElementType x, struct Node* p) {
    struct Node* tmp = (struct Node*) malloc(sizeof(struct Node));
    tmp->data = x;
    tmp->next = p->next;
    p->next = tmp;
}

void print(struct Node* p) {
    while (p->next!= NULL) {
        printf("%d ", p->next->data);
        p = p->next;
    }
    printf("\n");
}

void delete_node(struct Node* p) {
    struct Node* behind = p->next;
    p->next = behind->next;
    free(behind);
}

int get_size(struct Node* p) {
    int size = 0;
    while (p->next!=NULL) {
        size += 1;
        p = p->next;
    }
    return size;
}

int main() {
    struct Node *header;
    struct Node *p;
    header = new_node();
    insert_node(40, header);
    insert_node(30, header);
    insert_node(20, header);
    insert_node(10, header);
    print(header);
    p = header->next->next;
    delete_node(p);
    print(header);
    return 0;
}