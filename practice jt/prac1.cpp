#include <stdbool.h>
#include <stdio.h>
#include <math.h>
int matrix[8][8];
int maxsum = 0;
bool isvalid(int row,int col,int queen[]){
    for(int i = 0;i<row;i++){
        if(col == queen[i]) return false;
        if(abs(col-queen[i])==abs(row-i)) return false;
    }
    return true;
}
void func(int row,int queen[],int currentsum){
    if(row==8){
        if(currentsum>maxsum){
            maxsum = currentsum;
        }
        return;
    }
    for(int col = 0;col<8;col++){
        if(isvalid(row,col,queen)){
            queen[row] = col;
            func(row+1,queen,currentsum+matrix[row][col]);
        }
    }
}
int main(){
    for(int i = 0;i<8;i++){
        for(int j = 0;j<8;j++){
            scanf("%d",&matrix[i][j]);
        }
    }
    int queen[8];
    func(0,queen,0);
    printf("%d",maxsum);
    return 0;
}