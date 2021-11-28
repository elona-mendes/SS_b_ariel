#include <stdio.h>
#include <stdlib.h>
#include "my_mat.h"

int arr[10][10];
int newarr[10][10];

int main(){
    int i, j;
    char letter;
    while(1){
        scanf("%c", &letter);
        if (letter == 'A'){
            add_mat();
        }
        else if(letter == 'B'){
            scanf("%d %d", &i, &j);
            int isEx = is_way_exist(i, j);
            if(isEx == 0){
                printf("False\n");
            }
            else{
                printf("True\n");
            }
        }
        else if(letter == 'C'){
            scanf("%d %d", &i, &j);
            int sml = smallest_way(i, j);
            if(sml == 0){
                printf("%d\n", -1);
            }
            else{
                printf("%d\n", sml);
            }
            
        }
        else if(letter == 'D'){
            exit(0);
        }
    }
}
