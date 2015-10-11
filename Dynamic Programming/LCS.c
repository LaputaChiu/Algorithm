#include <stdio.h>
#define MAX(a,b) ((a>b)?a:b)
	
enum direct{
	LEFT,
	UP,
	LEFT_CORNER	
};

void Print_LCS(char *str1, char **DP_array, char **DP_array_backtrace, int i, int j){
	if(i==0 || j==0) return;
	
	switch(DP_array_backtrace[i][j]){
		case LEFT: Print_LCS(str1, DP_array, DP_array_backtrace, i, j-1); break;
		case UP: Print_LCS(str1, DP_array, DP_array_backtrace, i-1 , j); break;
		case LEFT_CORNER: Print_LCS(str1, DP_array, DP_array_backtrace, i-1 , j-1); printf(" %c ", str1[i-1]); break;
	}
}

// 2'd array space with backtrace
int LCS(char *str1, int len1, char *str2, int len2){
	int i = 0,j = 0;
	char **DP_array = (char**)calloc(len1+1,sizeof(char*));
	char **DP_array_backtrace = (char**)calloc(len1+1,sizeof(char*));
	for(i=0;i<=len1;i++){
		DP_array[i] = (char*)calloc(len2+1,sizeof(char));
		DP_array_backtrace[i] = (char*)calloc(len2+1,sizeof(char));
	}
	
	for(i=1;i<=len1;i++){
		for(j=1;j<=len2;j++){
			DP_array[i][j] = (str1[i-1] == str2[j-1])?
				(DP_array_backtrace[i][j] = LEFT_CORNER,DP_array[i-1][j-1]+1):
				(DP_array[i-1][j]>DP_array[i][j-1])?(DP_array_backtrace[i][j] = UP,DP_array[i-1][j]):(DP_array_backtrace[i][j] = LEFT,DP_array[i][j-1]);
			//printf(" %d ",DP_array[i][j]);
			//printf(" %d ",DP_array_backtrace[i][j]);
		}
		//printf("\n");
	}
	
	printf("LCS length: %d\n",DP_array[len1][len2]);
	
	// backtrace
	Print_LCS(str1, DP_array, DP_array_backtrace, len1, len2);
	printf("\n");
	
	for(i=0;i<=len1;i++){
		free(DP_array[i]);
	}
	free(DP_array);
}

// 1'd array space and 1 variable for storing left corner, to calculate length of LCS only.
void LCS_Length_low_memory(char *str1, int len1, char *str2, int len2){
	int i = 0,j = 0;
	char left_corner = 0;
	char *DP_array = (char*)calloc(len2+1,sizeof(char));
	
	for(i=0;i<len1;i++){
		for(j=1;j<=len2;j++){
			char tmp = DP_array[j]; // for next round's left corner
			DP_array[j] = (str1[i] == str2[j-1])?left_corner+1:MAX(DP_array[j-1],DP_array[j]);
			left_corner = tmp;
			//printf(" %d ",DP_array[j]);
		}
		left_corner = 0;
		//printf("\n");
	}
	
	printf("LCS length(low memory): %d\n",DP_array[len2]);
	free(DP_array);
}

int main(){
	char str1[] = "DEBWEF";
	char str2[] = "ENWERNT";
	LCS(str1, strlen(str1), str2, strlen(str2));
	LCS_Length_low_memory(str1, strlen(str1), str2, strlen(str2));
	return 0;
}
