#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"CountSort.h"

int main(void) {
	int num;
	printf("请输入1-9数值开始插入排序\n");
	printf("输入0会结束程序\n");
	scanf_s("%d", &num);
	fflush(stdin);
	while (num) {
		int len;
		if (num <= 9 && num >= 1) {
			clock_t start = clock();
 			printf("请输入数组的长度为：\n");
			scanf_s("%d", &len);
			fflush(stdin);
			int* a = (int*)malloc(sizeof(int) * len);
			printf("请输入数据：\n");
			for (int i = 0; i < len; i++) {
				scanf_s("%d", &a[i]); 
				fflush(stdin);
			}
			printf("当前数组的秩序为：\n");
			for (int i = 0; i < len; i++) {
				printf("%5d", a[i]);
			}
			printf("\n");
			CountSort(a, len);
			printf("排序完后的数组秩序：\n");
			for (int i = 0; i < len; i++) {
				printf("%5d", a[i]);
			}
			printf("\n");
			clock_t diff = (clock() - start) / CLOCKS_PER_SEC;
			printf("Running time:%dms\n", diff);
		}
		if(num>9||num<0) {
			printf("非法输入，请输入合法数字\n");
			continue;
		}
		if (num == 0) break;
		printf("请输入一个整数继续操作\n");
		scanf_s("%d", &num);
		fflush(stdin);
	}
	printf("结束啦，期待你下次的到来\n");
	return 0;
}