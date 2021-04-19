#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"QuickSort.h"

int main(void) {
	int num;
	printf("输入1-9开始程序\n");
	printf("输入0结束程序\n");
	scanf_s("%d", &num);
	fflush(stdin);
		while (num) {
			if (num <= 9 && num >= 1) {
			clock_t start = clock();
			int len;
			printf("请输入数组的长度\n");
			scanf_s("%d", &len);
			fflush(stdin);
			int* a = (int*)malloc(len * sizeof(int));
			printf("请输入数据\n");
			for (int i = 0; i < len; i++) {
				scanf_s("%d", &a[i]);
				fflush(stdin);
			}
			printf("当前数组的秩序\n");
			for (int i = 0; i < len; i++) {
				printf("%5d", a[i]);
			}
			printf("\n");
			QuickSort(a, 0, len - 1);
			clock_t diff = (clock() - start) / CLOCKS_PER_SEC;
			printf("Running time:%dms", diff);
			printf("排序后的数组的秩序\n");
			for (int i = 0; i < len; i++) {
				printf("%5d", a[i]);
			}
			printf("\n");
		}
	if (num == 0) break;
	if (num < 0 || num>9) {
		printf("非法输入，请输入合法整数");
		continue;
	}
	printf("继续输入一个合法整数进行操作\n");
	scanf_s("%d", &num);
	}
	printf("结束啦，期待你下次的到来\n");
	return 0;
}