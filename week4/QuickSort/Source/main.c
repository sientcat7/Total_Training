#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"QuickSort.h"

int main(void) {
	int num;
	printf("����1-9��ʼ����\n");
	printf("����0��������\n");
	scanf_s("%d", &num);
	fflush(stdin);
		while (num) {
			if (num <= 9 && num >= 1) {
			clock_t start = clock();
			int len;
			printf("����������ĳ���\n");
			scanf_s("%d", &len);
			fflush(stdin);
			int* a = (int*)malloc(len * sizeof(int));
			printf("����������\n");
			for (int i = 0; i < len; i++) {
				scanf_s("%d", &a[i]);
				fflush(stdin);
			}
			printf("��ǰ���������\n");
			for (int i = 0; i < len; i++) {
				printf("%5d", a[i]);
			}
			printf("\n");
			QuickSort(a, 0, len - 1);
			clock_t diff = (clock() - start) / CLOCKS_PER_SEC;
			printf("Running time:%dms", diff);
			printf("���������������\n");
			for (int i = 0; i < len; i++) {
				printf("%5d", a[i]);
			}
			printf("\n");
		}
	if (num == 0) break;
	if (num < 0 || num>9) {
		printf("�Ƿ����룬������Ϸ�����");
		continue;
	}
	printf("��������һ���Ϸ��������в���\n");
	scanf_s("%d", &num);
	}
	printf("���������ڴ����´εĵ���\n");
	return 0;
}