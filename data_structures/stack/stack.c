#include <stdio.h>
#include <malloc.h>

typedef int ElementType;
typedef struct {
    ElementType *elements;
    int top, capacity;
}Stack;

void makenull(Stack *s) {
    s->top = -1;
    s->capacity = 1;
    s->elements = (ElementType*) malloc(sizeof(ElementType));
}

int is_empty(Stack s) {
    return s.top == -1;
}

void push(ElementType x, Stack *s) {
    if (s->top == s->capacity - 1) {
        s->elements = (ElementType*) realloc(s->elements,sizeof(ElementType)*(s->capacity*2));
        s->capacity *= 2;
    }
    s->top += 1;
    *(s->elements + s->top) = x;
}

ElementType pop(Stack *s) {
    if (!is_empty(*s)) {
        ElementType data = *(s->elements + s->top);
        s->top -= 1;
        return data;
    }
    return -10000;
}

void print(Stack *s){
    while (!is_empty(*s)) {
        ElementType x = pop(s);
        printf("%d ", x);
    }
    printf("\n");
}

void to_binary(int n, Stack *s) {
    makenull(s);
    while (n>0) {
        push(n%2, s);
        n=n/2;
    }
}

char get_hexa(int k) {
    char tmp[] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
    return tmp[k];
}

void to_hexa(int n, Stack *s) {
    makenull(s);
    while (n>0) {
        int k = n%16;
        push(get_hexa(k), s);
        n=n/16;
    }
}

int get_priority(char op)
{
    if (op == '*' || op == '/')
        return 2;
    if (op == '+' || op == '-')
        return 1;
    return 0;
}

void to_posfix(char st[], char st_out[]) {
    int i=0;
    int j=0;
    Stack s;
    makenull(&s);
    while (st[i] != '\0' && st[i] != '\n') {
        char t = st[i];
        if (t >= 'A' && t <= 'Z') {
            st_out[j] = t;
            j++;
        }else if (t >= 'a' && t <= 'z') {
            st_out[j] = t;
            j++;
        }else if (t == '(') {
            push(t, &s);
        }else if (t == ')') {
            char x;
            while (s.elements[s.top] != '(') {
            x = pop(&s);
            st_out[j] = x;
            j++;
        }
        if (s.elements[s.top] == '(') {
            pop(&s);
        }
        }else if (t == '+' || t=='-' || t=='*' || t=='/') {
        if (s.elements[s.top] == '+' || s.elements[s.top] =='-' || s.elements[s.top] =='*' || s.elements[s.top] =='/') {
            if (get_priority(s.elements[s.top]) >= get_priority(t)) {
                char x = pop(&s);
                st_out[j] = x;
                j++;
            }
        }
            push(t, &s);
        }
        i++;
    }
    while (!is_empty(s)){
        char x = pop(&s);
        st_out[j] = x;
        j++;
    }
    st_out[j] = '\0';
}

int main() {
    int n;
    Stack S;
    scanf("%d",&n);
    to_hexa(n, &S);
    print(&S);
    return 0;
}