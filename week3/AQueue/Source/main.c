#include<stdio.h>
#include<stdlib.h>
#include"AQueue.h"

int main(void) {
	int n;
	AQueue *Q;
	Q = (AQueue*)malloc(sizeof(AQueue));
	printf("请输入一个整数开始下面的队列的相关功能\n");
	printf("1.初始化一个空队列\n");
	printf("2将新元素入列.\n");
	printf("3将列头元素出列.\n");
	printf("4判断队列是否为空.\n");
	printf("5.判断队列是否为满\n");
	printf("6.清空队列\n");
	printf("7.获得列顶元素\n");
	printf("8获得当前队列长度.\n");
	printf("9.遍历队列并打印各元素的值\n");
	printf("10.销毁队列并退出当前程序\n");
	scanf_s("%d", &n);
	while (n) {
		switch (n) {
		case 1:InitQueue(Q);break;
		case 2: {
			int t;
			printf("你想要入列哪种类型\n");
			printf("1.整型 2.字符型 3.浮点型 \n");
			scanf_s("%d", &t);
			while (t < 1 || t>3) {
				printf("请输入[1,3]之间的整数，请重新输入\n");
				scanf_s("%d", &t);
			}
			printf("请输入要入列的数据\n");
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
		printf("请输入一个整数继续进行操作\n");
		scanf_s("%d", &n);
	}
	printf("结束啦，期待你下次的到来\n");
	return 0;
}