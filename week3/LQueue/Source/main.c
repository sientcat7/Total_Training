#include<stdio.h>
#include<stdlib.h>

#include"LQueue.h"

int main(void) {
	LinkQueue *Q;
	Q = (LinkQueue*)malloc(sizeof(LinkQueue));
	int n;
	printf("������һ��������ʼ����Ķ��е���ع���\n");
	printf("1.��ʼ��һ���ն���\n");
	printf("2����Ԫ������.\n");
	printf("3����ͷԪ�س���.\n");
	printf("4�ж϶����Ƿ�Ϊ��.\n");
	printf("5.��ն���\n");
	printf("6.����ж�Ԫ��\n");
	printf("7��õ�ǰ���г���.\n");
	printf("8.�������в���ӡ��Ԫ�ص�ֵ\n");
	printf("9.���ٶ��в��˳���ǰ����\n");
	scanf_s("%d", &n);
	while (n) {
		switch(n)
		{
		case 1:InitQueue(Q); break;
		case 2: {
			int t;
			printf("����Ҫ������������\n");
			printf("1.���� 2.�ַ��� 3.������ \n");
			scanf_s("%d", &t);
			while (t < 1 || t>4) {
				printf("������[1,4]֮�������������������\n");
				scanf_s("%d", &t);
			}
			printf("������Ҫ���е�����\n");
			switch (t) {
			case 1: {
				int a;
				scanf_s("%d", &a);
				
				EnQueue(Q, &a,t);
				break;
			}
			case 2: {
				char b;
				scanf_s("%c", &b);
				if (b == '\n') scanf_s("%c", &b);
				
				EnQueue(Q, &b,t);
				break;

			}
			case 3: {
				double c;
				scanf_s("%lf", &c);
				
				EnQueue(Q, &c,t);
				break;
			}
			}
			break;
		}
		case 3:DeQueue(Q); break;
		case 4:IsEmptyQueue(Q); break;
		case 5:ClearQueue(Q); break;
		case 6: {
			void* data = NULL;
			GetHeadQueue(Q, &data);
			break;
		}
		case 7:LengthQueue(Q); break;
		case 8:TraverseQueue(Q, foo); break;
		}
		if (n == 9) {
			DestoryQueue(Q);
			break;
		}
		printf("������һ�������������в���\n");
		scanf_s("%d", &n);
	}
	printf("���������ڴ����´εĵ���\n");
	return 0;
}
	
