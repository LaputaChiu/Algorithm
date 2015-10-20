#include <stdio.h>

// Recursive
void hanoi(int n, int *count){
	if(n == 1){
		(*count)++; return;
	}else{
		hanoi(n-1, count); // from A to B
		(*count)++;		// move the biggest one from A to C
		hanoi(n-1, count); // from B to C
	}
}

int main(){
	int count = 0;
	int n = 4;
	hanoi(n, &count);
	printf("Hanoi with %d discs : %d\n",n,count);
	return 0;
}
