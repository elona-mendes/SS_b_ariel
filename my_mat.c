#include <stdio.h>
#include "my_mat.h"
extern int arr[10][10];
extern int newarr[10][10]; //copy original arr
void findSmallestArr();

/* recive numbers and put them on matrix
(function "A")
*/
void add_mat(){
    for(int i =0; i<10; i++){
        for(int j = 0; j < 10; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }
    findSmallestArr();
}

/* will return if a way between i and j existe
if yes - return true, else - return false  
(function "B")
*/
int is_way_exist(int i, int j){
    int temp;
    if(i>j){
        temp = j;
        j = i;
        i = temp;
    }
    if(arr[i][j] == 0){
        return 0;
    }
    else{
        return 1;
    } 
}
/* will return the smallest way between i and j,
if there is no way, return -1
(function "C")
*/
int smallest_way(int i, int j){
    int temp;
    if(i>j){
        temp = j;
        j = i;
        i = temp;
    }
    return (arr[i][j]);
}

/* add "newarr" with the smallest way between 2 numbers*/
void findSmallestArr(){
    for(int k = 0; k<10; k++){
        for(int i = 0; i <10; i++){
            for(int j = 0; j<10; j++){
               if(j > i){
                if(arr[i][j] == 0) {
                    if((arr[i][k] !=0) && (arr[k][j] != 0)){
                        newarr[i][j] = arr[i][k] + arr[k][j];
                        arr[i][j] = newarr[i][j];
                        arr[j][i] = newarr[i][j];
                    }
                }
                else if((arr[i][k] ==0) || (arr[k][j] == 0)){
                    newarr[i][j] = arr[i][j];
                }

                else if ((arr[i][j]) <= (arr[i][k] + arr[k][j])){
                    newarr[i][j] = arr[i][j];
                }
                else{
                    newarr[i][j] = arr[i][k] + arr[k][j];
                    arr[i][j] = newarr[i][j];
                    arr[j][i] = newarr[i][j];
                }
             }                 
           }
        }
    }
}