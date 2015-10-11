/* Best Case:			O(n^2)
 * Worst Case:		O(n^2)
 * Average Case:	O(n^2)
 */

#include <stdio.h>
#include <stdbool.h>

#define PRINT_INT_ARRAY(array,size) { \
	int index = 0;	\
	printf("[");	\
	while(index < size) printf((index==0)?"%d":",%d",*(array+index)),index++;	\
	printf("]\n");	\
}

#define SWAP(a,b) {(a^=b, b^=a, a^=b);}

void SelectionSort(int *array, int size){
	int j = 0;
	while(--size){
		int max = 0;
		for(j=1;j<=size;j++) if(array[j] > array[max]) max = j;
		SWAP(array[size],array[max]);
	}
}

int main(){
	int array[10] = {5,3148,3617,126,565,6784,-3,-2123,31,0};
	SelectionSort(array, sizeof(array)/sizeof(int));
	PRINT_INT_ARRAY(array, sizeof(array)/sizeof(int));
	return 0;
}
