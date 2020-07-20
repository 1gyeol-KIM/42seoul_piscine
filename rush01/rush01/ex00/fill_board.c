#include <stdio.h>
#include <string.h>
int g_board[10][10];
int g_buf_x[10][10];
int g_buf_y[10][10];
int cnt;
int n;
void fill_board(int x, int y);
void sol(int x, int y);
void print_board(){
    printf("================== case : %d ==================\n", ++cnt);
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= n; ++j)
            printf("%d ", g_board[i][j]);
        puts("");
    }
    puts("");puts("");puts("");
    return ;
}
void sol(int x, int y){
    if(y > n){
        fill_board(x, y);
        return ;
    }
    for(int i = 1; i <= n; ++i){
        if(g_buf_x[x][i] || g_buf_y[y][i])
            continue;
        g_buf_x[x][i] = g_buf_y[y][i] = 1;
        g_board[x][y] = i;
        fill_board(x, y + 1);
        g_buf_x[x][i] = g_buf_y[y][i] = 0;
    }
}
void fill_board(int x, int y){
    if(x > n){
        print_board(); // 정당성 검사부분
    }
    if(y > n){
        fill_board(x + 1, 1);
    } else {
        sol(x, y);
    }
}
int main(){
    n = 3;
    fill_board(1, 1);
}
