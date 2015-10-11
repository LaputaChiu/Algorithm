/* Best Case:			O(n)
 * Worst Case:		O(n^2)
 * Average Case:	O(n^2)
 */

#include <stdio.h>
#include <stdbool.h>

#define PRINT_INT_ARRAY(array,size) { \
	int index = 0;	\
	printf("[");	\
	while(index < size) printf((index==0)?"%d":",%d",*(array+index)),index++;	\
	printf("]");	\
}

#define SWAP(a,b) {(a^=b, b^=a, a^=b);}

void BubbleSort(int *array, int size){
	int j = 0, swap_position = 1;
	
	while(--size && swap_position){
		for(j=swap_position,swap_position=0;j<=size;j++){
			if(array[j-1] > array[j]){ SWAP(array[j-1],array[j]); swap_position = j; }
		}
	}
}

int main(){
	int array[10] = {5,3148,3617,126,565,6784,-3,-2123,31,0};
	BubbleSort(array, sizeof(array)/sizeof(int));
	PRINT_INT_ARRAY(array, sizeof(array)/sizeof(int));
	return 0;
}
