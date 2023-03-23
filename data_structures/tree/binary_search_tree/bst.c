#include <stdio.h>
#include <malloc.h>

typedef int KeyType;
struct Node {
    KeyType key;
    struct Node* left;
    struct Node* right;
};
typedef struct Node* Tree;

void makenull(Tree *t) {
    *t = NULL;
}

void pre_order(Tree t) {
    if (t != NULL) {
        printf("%d ", t->key);
        pre_order(t->left);
        pre_order(t->right);
    }
}

void in_order(Tree t) {
    if (t != NULL) {
        in_order(t->left);
        printf("%d ", t->key);
        in_order(t->right);
    }
}

void post_order(Tree t) {
    if (t != NULL) {
        post_order(t->left);
        post_order(t->right);
        printf("%d ", t->key);
    }
}

Tree simple_search(Tree t, KeyType k) {
    if (t == NULL || t->key == k) {
        return t;
    }
    if (k > t->key) {
        return simple_search(t->right, k);
    }else{
        return simple_search(t->left, k);
    }
    return NULL;
} 

Tree search(Tree t, KeyType k, Tree *parent) {
    *parent = NULL;
    Tree p = t;
    while (p!=NULL) {
        KeyType pKey = p->key;
        if (pKey == k) {
            return p;
        }else{
            *parent = p;
            if (pKey < k) {
                p = p->right;
            }else{
                p = p->left;
            }
        }
    }
    return NULL;
}

void insert_node(Tree *t, KeyType k) {
    if (*t != NULL) {
        KeyType tKey = (*t)->key;
        if (tKey !=  k) {
            if (tKey > k) {
                insert_node(&((*t)->left), k);
            }else{
                insert_node(&((*t)->right), k);
            }
        }else{
            printf("Khoa nay da ton tai!\n");
        }
    }else {
        Tree tmp;
        tmp = (struct Node*) malloc(sizeof(struct Node));
        tmp->key = k;
        tmp->left = NULL;
        tmp->right = NULL;
        (*t) = tmp;
    }
}

void delete_key(Tree *t, KeyType k) {
    Tree parent;
    Tree p = search(*t, k, &parent);
    // Kiem tra hai cay con khong
    // Lay nut vua doi voi nut can xoa ra xoa duoi dang 
    // mot cay con hoac la
    if (p->left != NULL && p->right != NULL) {
        Tree q = p;
        p = p->right;
        while (p->left != NULL) {
            parent = p;
            p = p->left;
        }
        q->key = p->key;
    }
    // Lay cay con (sau khi xet 2 cay con / khi chi co mot cay con)
    Tree st = p->left;
    if (st == NULL) {
        st = p->right;
    }
    if (parent == NULL) {
        *t = st;
    }else if (parent->left == p) {
        parent->left = st;
    }else{
        parent->right = st;
    }
    free(p);
}

void print_tree(Tree t) {
    // Print bst
    printf("In cay: \n");
    in_order(t);
    printf("\n");
    pre_order(t);
    printf("\n");
    post_order(t);
    printf("\n");
}

int main() {
    Tree t;
    makenull(&t);

    // Insert bst
    int m;
    printf("Nhap vao so nut: ");
    scanf("%d", &m);
    while (m>0) {
        KeyType x = 0;
        scanf("%d", &x);
        insert_node(&t, x);
        m-=1;
    }

    print_tree(t);

    // Search bst
    int n;
    printf("Nhap gia tri cua nut can tim: ");
    scanf("%d", &n);
    Tree parent;
    Tree findOut = search(t, n, &parent);
    if (findOut!=NULL){
        printf("Da tim thay %d\n", findOut->key);
        printf("Nut cha %d\n", parent->key);
    }else{
        printf("Khong tim thay!\n");
    }

    // Delete node
    while (n!=911){
        printf("Nhap gia tri cua nut can xoa: ");
        scanf("%d", &n);
        if (n==911){
            break;
        }
        delete_key(&t, n);
        print_tree(t);
    }

    return 0;
}



