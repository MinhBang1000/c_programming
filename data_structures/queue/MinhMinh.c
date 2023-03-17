#include <stdio.h>
#include "MinhMinh.h"

// 1
// int main() {
//     Queue c1, c2;
//     makenull(&c1);
//     makenull(&c2);
//     int n;
//     // Write n
//     scanf("%d", &n);
//     int i;
//     // Write c1
//     for (i=0;i<n;i++) {
//         ElementType x;
//         scanf("%d", &x);
//         en_queue(x, &c1);
//     }
//     // Write c2
//     for (i=0;i<n;i++) {
//         ElementType x;
//         scanf("%d", &x);
//         en_queue(x, &c2);
//     }
//     i = 0;
//     while (!is_empty(c1)) {
//         ElementType y = de_queue(&c1);
//         if (y != front(c2)) {
//             en_queue(y, &c1);
//         }else {
//             de_queue(&c2);
//         }
//         i++;
//     }
//     printf("%d\n", i);
//     return 0;
// }

// 2
int main() {
    Queue c1;
    makenull(&c1);
    int n;
    scanf("%d", &n);
    int i;
    for (i=0;i<n;i++) {
        char ch;
        ElementType x;
        scanf(" %c", &ch);         
        if (ch == 'E') {
            scanf("%d", &x);
            en_queue(x, &c1);
            printf("%d\n", c1.size);
        }else {
            if (is_empty(c1)) {
                printf("%d %d\n", -1, 0);
            }else{
                x = de_queue(&c1);
                printf("%d %d\n", x, c1.size);
            }

        }
    }
    return 0;
}