#include<stdio.h>
#include<malloc.h>
#include<stdbool.h>

bool king_is_in_check (const char chessboard[8][8])
{   
    int i,j;
    for (i=0;i<8;i++) {
        for (j=0;j<8;j++) {
            switch (chessboard[i][j])
            {
                case 'Q':
                    
                    break;
                case 'B':
                    
                    break;
                case 'N':
                    
                    break;
                case 'R':
                    
                    break;
                case 'P':
                    
                    break;            
                default:
                    break;
            }
        }
    }   
    return false;  // good luck :)
}