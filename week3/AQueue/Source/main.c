#include<stdio.h>
#include<stdlib.h>
#include"AQueue.h"

int main(void) {
	int n;
	AQueue *Q;
	Q = (AQueue*)malloc(sizeof(AQueue));
	printf("������һ��������ʼ����Ķ��е���ع���\n");
	printf("1.��ʼ��һ���ն���\n");
	printf("2����Ԫ������.\n");
	printf("3����ͷԪ�س���.\n");
	printf("4�ж϶����Ƿ�Ϊ��.\n");
	printf("5.�ж϶����Ƿ�Ϊ��\n");
	printf("6.��ն���\n");
	printf("7.����ж�Ԫ��\n");
	printf("8��õ�ǰ���г���.\n");
	printf("9.�������в���ӡ��Ԫ�ص�ֵ\n");
	printf("10.���ٶ��в��˳���ǰ����\n");
	scanf_s("%d", &n);
	while (n) {
		switch (n) {
		case 1:InitQueue(Q);break;
		case 2: {
			int t;
			printf("����Ҫ������������\n");
			printf("1.���� 2.�ַ��� 3.������ \n");
			scanf_s("%d", &t);
			while (t < 1 || t>3) {
				printf("������[1,3]֮�������������������\n");
				scanf_s("%d", &t);
			}
			printf("������Ҫ���е�����\n");
			switch (t) {
			case 1: {
				int a;
				scanf_s("%d", &a);
				Q->type[Q->tail] = 1;
				EnQueue(Q, &a);
				break;
			}
			case 2: {
				char b;
					scanf_s("%c", &b);
					if (b == '\n') scanf_s("%c", &b);
					Q->type[Q->tail] = 2;
					EnQueue(Q, &b);
					break;
				
			}
			case 3: {
				double c;
				scanf_s("%lf", &c);
				Q->type[Q->tail] = 3;
				EnQueue(Q, &c);
				break;
			}
			}
			break;
		}
		case 3:DeQueue(Q); break;
		case 4:IsEmptyQueue(Q); break;
		case 5:IsFullQueue(Q); break;
		case 7: {
			void* data = NULL;
			GetHeadQueue(Q, &data);
			break;
		}
		case 6:ClearQueue(Q); break;
		case 8:LengthQueue(Q); break;
		case 9:TraverseQueue(Q,foo); break;
		}
		if (n == 10) {
			DestoryQueue(Q);
			break;
		}	
		printf("������һ�������������в���\n");
		scanf_s("%d", &n);
	}
	printf("���������ڴ����´εĵ���\n");
	return 0;
}