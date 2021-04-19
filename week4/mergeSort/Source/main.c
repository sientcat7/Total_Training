#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"mergeSort.h"

int main(void) {
	int num;
	printf("������һ��1-9������ʼ\n");
	printf("����0��������\n");
	scanf_s("%d", &num);
	fflush(stdin);
	while (num) {
		if (num <= 9 && num >= 1) {
			clock_t start = clock();
			int len;
			printf("������Ҫ��������ĳ���\n");
			scanf_s("%d", &len);
			fflush(stdin);
			int* a = (int*)malloc(len * sizeof(int));
			printf("��������:\n");
			for (int i = 0; i < len; i++) {
				scanf_s("%d", &a[i]);
				fflush(stdin);
			}
			printf("��ǰ���������Ϊ\n");
			for (int i = 0; i < len; i++) {
				printf("%5d", a[i]);
			}
			printf("\n");
			printf("ִ�����������������Ϊ\n");
			mergeSort(a, 0, len - 1, len);
			for (int i = 0; i < len; i++) {
				printf("%5d", a[i]);
			}
			printf("\n");
			clock_t diff = (clock() - start) / CLOCKS_PER_SEC;
			printf("Running time:%dms\n", diff);
		}
		if (num == 0) break;
		if(num>9||num<0){
			printf("�Ƿ����룬������һ���Ϸ�����\n");
			continue;
		}
		printf("��������һ���Ϸ��������в���\n");
		scanf_s("%d", &num);
		fflush(stdin);
	}
	printf("���������ڴ����´εĵ���\n");
	return 0;
}