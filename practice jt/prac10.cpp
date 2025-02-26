#include <stdio.h>
#include <stdbool.h>
int n; 
int c[50];
bool isallzero(){
    for(int i = 0;i<n;i++){
        if(c[i]!=0) return false;
    }
    return true;
}
bool isalleven(){
    for(int i = 0;i<n;i++){
        if(c[i]%2 != 0) return false;
    }
    return true;
}
void dividetwo(){
    for(int i = 0;i<n;i++){
        c[i] /= 2;
    }
}
int min(){
    int operation=0;
    while(!isallzero()){
        if(!isalleven()){
            for(int i =0;i<n;i++){
                if(c[i]%2 !=0){
                    c[i] -=1;
                    operation++;
                }
            }
        }else{
            dividetwo();
            operation++;
        }
    }
    return operation;
}
int main(){
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &c[i]);
    }
    printf("%d\n", min());
    return 0;
}