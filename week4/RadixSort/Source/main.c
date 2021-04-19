#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"RaddixSort.h"

int main(void) {
	int num;
	printf("请输入一个1-9的数开始\n");
	printf("输入0结束程序\n");
	scanf_s("%d", &num);
	fflush(stdin);
	while (num) {
		if (num <= 9 && num >= 1) {
			clock_t start = clock();
			int len;
			printf("请输入要排序数组的长度\n");
			scanf_s("%d", &len);
			fflush(stdin);
			int* a = (int*)malloc(len * sizeof(int));
			int* c = (int*)calloc(len , sizeof(int));
			printf("输入数据:\n");
			for (int i = 0; i < len; i++) {
				scanf_s("%d", &a[i]);
				fflush(stdin);
			}
			printf("当前数组的秩序为\n");
			for (int i = 0; i < len; i++) {
				printf("%5d", a[i]);
			}
			printf("\n");
			printf("执行完排序数组的秩序为\n");
			RadixSort(a,&c,len);
			for (int i = 0; i < len; i++) {
				printf("%5d", c[i]);
			}
			printf("\n");
			clock_t diff = (clock() - start) / CLOCKS_PER_SEC;
			printf("Running time:%dms\n", diff);
		}
		if (num == 0) break;
		if (num > 9 || num < 0) {
			printf("非法输入，请输入一个合法的数\n");
			continue;
		}
		printf("继续输入一个合法整数进行操作\n");
		scanf_s("%d", &num);
		fflush(stdin);
	}
	printf("结束啦，期待你下次的到来\n");
	return 0;
}