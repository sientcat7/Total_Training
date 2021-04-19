#include<stdio.h>
#include<time.h>
#include"InsertSort.h"

/**
  *  @name        : void InsertSort(int* s, int n);
  *	@description : Sorting arrays in order
  *	@param		 : s,n
  *	@return		 : void
  *  @notice      : None
  */
void InsertSort(int* s, int n) {
	clock_t start = clock();
	int temp = 0,j = 0;
	for (int i = 1; i < n; i++) {
		temp = s[i];
		for ( j = i - 1; (j >= 0) && (s[j] > temp); j--) {
			s[j + 1] = s[j];
		}
		s[j + 1] = temp;
	}
	clock_t diff = clock() - start;
	printf("Running time：%dms\n", diff);
}