#include<stdio.h>
#include<stdlib.h>

#include"LQueue.h"

int main(void) {
	LinkQueue *Q;
	Q = (LinkQueue*)malloc(sizeof(LinkQueue));
	int n;
	printf("请输入一个整数开始下面的队列的相关功能\n");
	printf("1.初始化一个空队列\n");
	printf("2将新元素入列.\n");
	printf("3将列头元素出列.\n");
	printf("4判断队列是否为空.\n");
	printf("5.清空队列\n");
	printf("6.获得列顶元素\n");
	printf("7获得当前队列长度.\n");
	printf("8.遍历队列并打印各元素的值\n");
	printf("9.销毁队列并退出当前程序\n");
	scanf_s("%d", &n);
	while (n) {
		switch(n)
		{
		case 1:InitQueue(Q); break;
		case 2: {
			int t;
			printf("你想要入列哪种类型\n");
			printf("1.整型 2.字符型 3.浮点型 \n");
			scanf_s("%d", &t);
			while (t < 1 || t>4) {
				printf("请输入[1,4]之间的整数，请重新输入\n");
				scanf_s("%d", &t);
			}
			printf("请输入要入列的数据\n");
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
		printf("请输入一个整数继续进行操作\n");
		scanf_s("%d", &n);
	}
	printf("结束啦，期待你下次的到来\n");
	return 0;
}
	
