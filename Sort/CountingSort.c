#include <stdio.h>
#include <stdbool.h>

#define PRINT_INT_ARRAY(array,size) { \
	int index = 0;	\
	printf("[");	\
	while(index < size) printf((index==0)?"%d":",%d",*(array+index)),index++;	\
	printf("]\n");	\
}

/* assume array element is integer in the range 0 to k */
void CountingSort(int *array, int size, int k){
	int i = 0;
	int *sortArray = (int*)calloc(size, sizeof(int));
	int *countArray = (int*)calloc(k+1, sizeof(int));
	
	// count elements
	for(i=0;i<size;i++) countArray[array[i]]++;
	
	// calculate positions
	for(i=1;i<=k;i++) countArray[i] += countArray[i-1];
	
	// reorder
	for(i=size-1;i>=0;i--) sortArray[countArray[array[i]]---1] = array[i];

	memcpy(array, sortArray, size*sizeof(int));
	if(sortArray) free(sortArray);
	if(countArray) free(countArray);
}

int main(){
	int array[] = {0,4,55,2,5,4,0,55,2,55,123,123,123,4,4,2,2,2,2,2};
	CountingSort(array, sizeof(array)/sizeof(int), 123);
	PRINT_INT_ARRAY(array, sizeof(array)/sizeof(int));
	return 0;
}
