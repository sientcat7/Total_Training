#include<stdio.h>
#include<stdlib.h>
#include"BSTree.h"

int main(void) {
	BinarySortTreePtr *hbst ;
	hbst = (BinarySortTreePtr*)malloc(sizeof(BinarySortTreePtr)); //初始化二叉树
	printf("下面为功能对应的编码表\n");
	printf("1.插入节点\n");
	printf("2.查找节点\n");
	printf("3.删除节点\n");
	printf("4.递归先序遍历\n");
	printf("5.递归中序遍历\n");
	printf("6.递归后序遍历\n");
	printf("7.非递归先序遍历\n");
	printf("8.非递归中序遍历\n");
	printf("9.非递归后序遍历\n");
	printf("10.层次遍历\n");
	printf("11.退出程序\n");
	printf("=======================\n");
	int num;
	printf("请输入一个1-11的整数来进行操作\n");
	scanf_s("%d", &num);
	while (num) {
		if (num > 11 || num < 1) {
			printf("非法输入，请输入合法的整数\n");
			scanf_s("%d", &num);
			continue;
		}
		else if(num <= 11&&num >= 1) {
			switch (num)
			{

			case 1: {
				int data;
				printf("请输入要插入的数值\n");
				scanf_s("%d", &data);
				BST_insert(*hbst, data);
				break;
			}
			case 2:{
				int data;
				printf("请输入要查找节点对应的数值\n");
				scanf_s("%d", &data);
				BST_search(*hbst, data);
				break;
			}
			case 3: {
				int data;
				printf("请输入要删除节点对应的值\n");
				scanf_s("%d", &data);
				BST_delete(*hbst,data);
				break; 
			}
			case 4: BST_preorderI(*hbst,&visit); break;
			case 5: BST_inorderI(*hbst,&visit); break;
			case 6: BST_postorderI(*hbst,&visit); break;
			case 7: BST_inorderR(*hbst, &visit); break;
			case 8: BST_inorderR(*hbst, &visit); break;
			case 9: BST_postorderR(*hbst,&visit); break;
			case 10: BST_levelOrder(*hbst,&visit); break;
			}
			if (num == 11) {
				printf("结束啦，期待你下次的到来\n");
				break;
			}
			printf("继续输入一个合法整数进行操作\n");
			scanf_s("%d", &num);
		}
	}
	return 0;
}