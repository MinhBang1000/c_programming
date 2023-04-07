#include <stdio.h>
#include <malloc.h>

typedef int KeyType;
struct Node{
     KeyType key;
     struct Node* left;
     struct Node* right;
};
typedef struct Node* Tree;

Tree init_tree() {
    return NULL;
}

int is_empty(Tree t) {
    return t == NULL;
}

Tree insert_node(int x, Tree t) {
    if (is_empty(t)) {
        t = (struct Node*)malloc(sizeof(struct Node));
        t->key = x;
        t->left = NULL;
        t->right = NULL;
    }else if (x < t->key) {
        t->left = insert_node(x, t->left);
    }else if (x > t->key) {
        t->right = insert_node(x, t->right);
    }
    return t;
}

void pre_order(Tree t) {
    if (t!=NULL) {
        printf("%d ", t->key);
    }
    if (t->left != NULL) {
        pre_order(t->left);
    }
    if (t->right != NULL) {
        pre_order(t->right);
    }
}

void in_order(Tree t) {
    if (t->left != NULL) {
        in_order(t->left);
    }
    printf("%d ", t->key);
    if (t->right != NULL) {
        in_order(t->right);
    }
}

void post_order(Tree t) {
    if (t->left != NULL) {
        post_order(t->left);
    }
    if (t->right != NULL) {
        post_order(t->right);
    }
    printf("%d ", t->key);
}

Tree search(int x, Tree t) {
    if (t!=NULL && t->key!=x) {
        if (t->key < x) {
            return search(x, t->right);
        }else {
            return search(x, t->left);
        }
    }
    return t;
}

Tree search_adv(int x, Tree t, Tree *p) {
    if (t!=NULL && t->key!=x) {
        *p = t;
        if (t->key < x) {
            return search_adv(x, t->right, p);
        }else {
            return search_adv(x, t->left, p);
        }
    }
    return t;
}

Tree get_parent(int x, Tree t) {
    Tree p = NULL;
    search_adv(x, t, &p);
    return p;
}

Tree right_sibling(int x, Tree t) {
    Tree p = get_parent(x, t);
    Tree n = search(x, t);
    if (p->left == n) {
        return p->right;
    }
    return NULL;
}

Tree print_path_core(int x, Tree t) {
    if (t!=NULL && t->key!=x) {
        printf("%d ", t->key);
        if (t->key < x) {
            return print_path_core(x, t->right);
        }else {
            return print_path_core(x, t->left);
        }
    }
    return t;
} 

void print_path(int x, Tree t) {
    Tree n = print_path_core(x, t);
    if (n == NULL) {
        printf(" --> Tim khong thay");
    }else{
        printf("%d  --> Tim thay", x);
    }
}

Tree delete_node(int x, Tree t) {
    Tree p = get_parent(x, t);
    Tree n = search(x, t);
    if (n->left != NULL && n->right != NULL) {
        Tree le_left = n->right;
        Tree parent_of_le_left = n;
        while (le_left->left != NULL) {
            parent_of_le_left = le_left;
            le_left = le_left->left;
        }
        n->key = le_left->key;
        parent_of_le_left->left = le_left->right;
        free(le_left);
    }else if (n->left == NULL) {
        if (p->left == n) {
            p->left = n->right;
        }else{
            p->right = n->right;
        }
        free(n);
    }else if (n->right == NULL) {
        if (p->left == n) {
            p->left = n->left;
        }else{
            p->right = n->left;
        }
        free(n);
    }else{
        if (p->left == n) {
            p->left = NULL;
        }else{
            p->right = NULL;
        }
        free(n);
    }
    return t;
    
}

int main() {
Tree T = NULL;

int x;

T = insert_node(27,T);
T = insert_node(12,T);
T = insert_node(40,T);
T = insert_node(4,T);
T = insert_node(20,T);
T = insert_node(34,T);
T = insert_node(30,T); 
T = insert_node(50,T); 
x = 12;

T = delete_node(x, T);
in_order(T);
    return 0;
}