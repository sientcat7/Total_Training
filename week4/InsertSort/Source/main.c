#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include"InsertSort.h"

int main(void) {
	int num;
	printf("������1-9��ֵ��ʼ��������\n");
	printf("����0���������\n");
	scanf_s("%d", &num);
	while (num) {
		int n;
		if (num <= 9 && num >= 1) {

			printf("����������ĳ���Ϊ��\n");
			scanf_s("%d", &n);
			int* a = (int*)malloc(sizeof(int) * n);
			printf("���������ݣ�\n");
			for (int i = 0; i < n; i++) {
				scanf_s("%d", &a[i]); fflush(stdin);
					;
			}
			printf("��ǰ���������Ϊ��\n");
			for (int i = 0; i < n; i++) {
				printf("%5d", a[i]);
			}
			printf("\n");
			InsertSort(a, n);
			printf("����������������\n");
			for (int i = 0; i < n; i++) {
				printf("%5d", a[i]);
			}
			printf("\n");
		}
		else printf("�Ƿ����룬������Ϸ�����\n"); continue;
		if (n == 0) break;
			printf("������һ��������������\n");
			scanf_s("%d", &num);
	}
	printf("���������ڴ����´εĵ���\n");
	return 0;
}