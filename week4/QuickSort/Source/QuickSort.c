/***************************************************************************************
 *	File Name				:	QuickSort.c
 *	CopyRight				:	2021 QG Studio
 *	SYSTEM					:   win10
 *	Create Data				:	2021.4.17
 *
 *
 *--------------------------------Revision History--------------------------------------
 *	No	version		Data			Revised By			Item			Description
 *
 *
 ***************************************************************************************/

#include<stdio.h>
#include"QuickSort.h"

 /**
  *  @name        : void QuickSort(int* a, int start, int end);
  *	@description : Perform quick sort
  *	@param		 : *a,start,end
  *	@return		 : void
  *  @notice      : None
  */
void QuickSort(int* a,int start,int end) {
	int temp;
	int pivot = a[start];
	int i = start, j = end;
	if (start >= end) return;
	while (start < end) {
		while (start < end && a[end] >= pivot) --end;
		if (pivot > a[end]) {
			temp = a[start];
			a[start] = a[end];
			a[end] = temp;
			start++;
		}
		
		while (start < end && a[start] <= pivot) ++start;
		if (pivot < a[start]) {
			temp = a[start];
			a[start] = a[end];
			a[end] = temp;
			end--;
		}
	}
	QuickSort(a, i, start - 1);
	QuickSort(a, start+1, j);
}