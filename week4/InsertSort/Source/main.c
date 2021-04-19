#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include"InsertSort.h"

int main(void) {
	int num;
	printf("请输入1-9数值开始插入排序\n");
	printf("输入0会结束程序\n");
	scanf_s("%d", &num);
	while (num) {
		int n;
		if (num <= 9 && num >= 1) {

			printf("请输入数组的长度为：\n");
			scanf_s("%d", &n);
			int* a = (int*)malloc(sizeof(int) * n);
			printf("请输入数据：\n");
			for (int i = 0; i < n; i++) {
				scanf_s("%d", &a[i]); fflush(stdin);
					;
			}
			printf("当前数组的秩序为：\n");
			for (int i = 0; i < n; i++) {
				printf("%5d", a[i]);
			}
			printf("\n");
			InsertSort(a, n);
			printf("排序完后的数组秩序：\n");
			for (int i = 0; i < n; i++) {
				printf("%5d", a[i]);
			}
			printf("\n");
		}
		else printf("非法输入，请输入合法数字\n"); continue;
		if (n == 0) break;
			printf("请输入一个整数继续操作\n");
			scanf_s("%d", &num);
	}
	printf("结束啦，期待你下次的到来\n");
	return 0;
}