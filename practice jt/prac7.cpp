#include <stdio.h>
#include <string.h>

#define MAX_N 50
#define MAX_Q 1000

int getdirection(char a){
    if(a=='L') return 0;
    if(a=='R') return 1;
    if(a=='U') return 2;
    if(a=='D') return 3;
    return -1;
}

int main(){
    int dx[] = {0,0,-1,1};
    int dy[] = {-1,1,0,0};

    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        char matrix[n][n];
        int startx=-1,starty=-1,desx=-1,desy=-1;
        for(int i = 0;i<n;i++){
            scanf("%s",matrix[i]);
            for(int j = 0;j<n;j++){
                if(matrix[i][j]=='S'){
                    startx = i;
                    starty=j;
                }
                if(matrix[i][j]=='T'){
                    desx = i;
                    desy = j;
                }
            }
        }
        int q;
        scanf("%d",&q);
        while(q--){
            char command[1000];
            scanf("%s",command);
            int x = startx;
            int y = starty;
            int reached=0;
            int trap=0;
            int outofbound=0;
            for(int i =0;command[i]!='\0';i++){
                int d = getdirection(command[i]);
                x += dx[d];
                y += dy[d];
                
                if(x<0 || x>=n|| y<0||y>=n){
                    outofbound = 1;
                    break;
                }
                if(matrix[x][y]=='#'){
                    trap = 1;
                    break;
                }
                if(x==desx && y==desy){
                    reached=1;
                    break;
                }
            }
            if (outofbound) {
                printf("I am out!\n");
            } else if (trap) {
                printf("I am dizzy!\n");
            } else if (reached) {
                printf("I get there!\n");
            } else {
                printf("I have no idea!\n");
            }
        }
        
    }
    return 0;
}