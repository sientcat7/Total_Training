#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"CountSort.h"

int main(void) {
	int num;
	printf("������1-9��ֵ��ʼ��������\n");
	printf("����0���������\n");
	scanf_s("%d", &num);
	fflush(stdin);
	while (num) {
		int len;
		if (num <= 9 && num >= 1) {
			clock_t start = clock();
 			printf("����������ĳ���Ϊ��\n");
			scanf_s("%d", &len);
			fflush(stdin);
			int* a = (int*)malloc(sizeof(int) * len);
			printf("���������ݣ�\n");
			for (int i = 0; i < len; i++) {
				scanf_s("%d", &a[i]); 
				fflush(stdin);
			}
			printf("��ǰ���������Ϊ��\n");
			for (int i = 0; i < len; i++) {
				printf("%5d", a[i]);
			}
			printf("\n");
			CountSort(a, len);
			printf("����������������\n");
			for (int i = 0; i < len; i++) {
				printf("%5d", a[i]);
			}
			printf("\n");
			clock_t diff = (clock() - start) / CLOCKS_PER_SEC;
			printf("Running time:%dms\n", diff);
		}
		if(num>9||num<0) {
			printf("�Ƿ����룬������Ϸ�����\n");
			continue;
		}
		if (num == 0) break;
		printf("������һ��������������\n");
		scanf_s("%d", &num);
		fflush(stdin);
	}
	printf("���������ڴ����´εĵ���\n");
	return 0;
}