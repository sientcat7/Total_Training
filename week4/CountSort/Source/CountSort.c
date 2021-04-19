#include<stdio.h>
#include<stdlib.h>
#include"CountSort.h"

void CountSort(int* a, int len) {
	int max = a[0];
	int min = a[0];
	for (int i = 0; i < len; i++) {
		if (a[i] > max) {
			max = a[i];
		}
		if (a[min] < a[i]) {
			min = a[i];
		}
	}
	int range = max - min + 1;
	int* b = (int*)calloc(range, sizeof(int));
	for (int i = 0; i < len; i++) {
		b[a[i] - min] += 1;
	}
	int j = 0;
	for (int i = 0; i < range; i++) {
		while (b[i]--) {
			a[j++] = i + min;
		}
	}
	free(b); //将存储空间为空的数组b销毁
	b = NULL;
}