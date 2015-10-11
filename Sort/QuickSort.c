#include <stdio.h>
#include <stdbool.h>

#define PRINT_INT_ARRAY(array,size) { \
	int index = 0;	\
	printf("[");	\
	while(index < size) printf((index==0)?"%d":",%d",*(array+index)),index++;	\
	printf("]");	\
}

#define SWAP(a,b) {(a^=b, b^=a, a^=b);}

// pick first integer as pivot
void QuickSort(int *array, int begin, int end){
	int i = 0, j = 0;
	if(begin<end){
		while(true){
			// find first interger greater than pivot
			for(i=begin+1;i<=end && array[i] < array[begin];i++);
			// find first interger lesser than pivot
			for(j=end;j>=begin+1 && array[j] > array[begin];j--);
			if(i >= j) break;
			SWAP(array[i],array[j]);
		}
		SWAP(array[begin],array[j]);
		QuickSort(array,begin,j-1);
		QuickSort(array,j+1,end);
	}
}

int main(){
	int array[10] = {5,3148,3617,126,565,6784,-3,-2123,31,0};
	QuickSort(array, 0, 9);
	PRINT_INT_ARRAY(array, sizeof(array)/sizeof(int));
	return 0;
}
