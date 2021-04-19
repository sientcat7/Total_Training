/***************************************************************************************
 *	File Name				:	mergeSort.c
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
#include<stdlib.h>
#include"mergeSort.h"

void merge(int* a, int start, int mid, int end,int len) {
	int* result = (int*)malloc(len * sizeof(int));
	int k = 0, i = start, j = mid + 1;
	while (i <= mid && j <= end) {
		if (a[i] < a[j]) {
			result[k++] = a[i++];
		}
		else {
			result[k++] = a[j++];
		}
	}
	if (i == mid + 1) {
		while (j <= end) {
			result[k++] = a[j++];
		}
	}
	if (j == end + 1) {
		while (i <= mid) {
			result[k++] = a[i++];
		}
	}
	for (j = 0, i = start; j < k; i++, j++) {
		a[i] = result[j];
	}
}


void mergeSort(int* a, int start, int end, int len) {
	if (start >= end) return;
	else {
		int mid = (start + end) / 2;
		mergeSort(a, start, mid, len);
		mergeSort(a, mid + 1, end, len);
		merge(a, start, mid,end, len);
	}
}