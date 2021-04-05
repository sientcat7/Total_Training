#include<stdio.h>
#include"linkStack.h"

int main(void) {
	int n;
	LinkStack head;
	printf("请输入一个整数\n");
	printf("1.初始化一个空栈\n");
	printf("2.将新元素入栈\n");
	printf("3.将栈顶元素出栈\n");
	printf("4.获取当前栈的长度\n");
	printf("5.判断栈是否为空栈\n");
	printf("6.获得栈顶元素\n");
	printf("7.销毁链栈\n");
	scanf_s("%d", &n);
	while (n) {
		switch (n) {
		case 1:initStack(&head); break;
		case 2: {
			int data1 = 0;
			printf("请输入要插入元素的值\n");
			scanf_s("%d", &data1);
			push(&head, data1);
			break;
		}
		case 3: {
			int *data2 = 0;
			pop(&head, &data2);
			break;
		}
		case 4:
		{
			int length = 0;
			stackLength(&head, length);
			break;
		}
		case 5:isEmpty(&head); break;
		case 6: {
			int *data3 = 0;
			getTopStack(&head, &data3);
			break;
		}
		}
		if (n == 7) {
			destorylinkstack(&head);
			break;
		}
		if(n>7||n<1){
			printf("输入非法\n");
		}
		printf("请输入一个整数，继续操作\n");
		scanf_s("%d", &n);
	}
	printf("结束啦，期待你下一次的到来\n");
	return 0;
}