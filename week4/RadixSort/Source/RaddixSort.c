
#include<stdio.h>
#include<stdlib.h>
#include"RaddixSort.h"

int GetDigit(int num, int i) { //i为取整数num的位数
	while (i > 1) {
		num /= 10;
		i--;
	}
	return num % 10;
}
void RadixSort(int* a,int **c, int len) {
	int i, j, k, l, digit;
	int** b = (int**)malloc(sizeof(int*) * 10);  //sizeof(int*),不能少*，一个指针的内存大小，每个元素是一个指针。
	for (i = 0; i < 10; i++)
	{
		b[i] = (int*)malloc(sizeof(int) * len);
	}
	for (i = 1; i <= 5; i++) {
		int flag = 0; //用于记录是否取到整数阿最高位数
		for (j = 0; j < len; j++) {
			digit = GetDigit(a[j], i);
			k = 0;
			while (b[digit][k]) {
				k++;
			}
			b[digit][k] = a[j];
			printf("%d", b[digit][k]);
			if (!digit) flag = 1;
		}
		if (flag)break;
		l = 0;
		for (j = 0; j < 10; j++) {
			k = 0;
			if (b[j][0] == 0) continue;
			while (b[j][k] > 0) {
				c[l++] = b[j][k++];
			}
		}
		free(b);
		int** b = (int**)malloc(sizeof(int*) * 10);  //sizeof(int*),不能少*，一个指针的内存大小，每个元素是一个指针。
		for (i = 0; i < 10; i++)
		{
			b[i] = (int*)malloc(sizeof(int) * len);
		}
	}
}
