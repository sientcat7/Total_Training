#include<stdio.h>
#include"Stack.h"

int main(void) {
	SqStack s;
	int n;
	printf("请输入一个整数\n");
	printf("1.初始化一个栈\n");
	printf("2.将元素入栈\n");
	printf("3.将元素出栈\n");
	printf("4.判断是否为空栈\n");
	printf("5.得到栈顶元素\n");
	printf("6.检测栈的大小\n");
	printf("7.清空栈\n");
	printf("8.销毁栈\n");
	scanf_s("%d", &n);
	while (n) {
		switch (n)
		{
		case 1: {
			int size;
			printf("请输入栈的最大长度\n");
			scanf_s("%d", &size);
			init_Stack(&s,size); 
			break;
		}
		case 2: {
			int data;
			printf("输入要放到栈顶的值\n");
			scanf_s("%d", &data);
			pushStack(&s, data); 
			break; 
		}
		case 3:popStack(&s); break;
		case 4:isEmptyStack(&s); break;
		case 5:getTopStack(&s); break;
		case 6:stackLength(&s); break;
		case 7:clearStack(&s); break;
		}
		if (n == 8)
		{
			destoryStack(&s);
			break;
		}
		printf("请输入一个整数,继续操作\n");
		scanf_s("%d", &n);
	}
	printf("结束啦，期待你下次的到来\n");
	return 0;
}