#include <stdio.h>

int n;
char buf[10];
void recursive(int depth, int prev){
	if(depth == n){
		printf("%s, ", buf);
		return ;
	}
	if(prev > 9)
		return;

	for(int i = prev; i < 10; ++i){
		buf[depth] = '0' + i;
		recursive(depth + 1, i + 1);

	}

}
// char str[10] = "123456789";
/*
void recur(int idx){
	if(!str[idx])
		return;
	recur(idx + 1);
	printf("%c", str[idx]);

}
*/
int main(){
	//scanf("%d", &n);
	//recursive(0, 0);
	recur(0);
}
