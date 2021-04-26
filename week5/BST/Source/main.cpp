#include<stdio.h>
#include<stdlib.h>
#include"BSTree.h"

int main(void) {
	BinarySortTreePtr *hbst ;
	hbst = (BinarySortTreePtr*)malloc(sizeof(BinarySortTreePtr)); //��ʼ��������
	printf("����Ϊ���ܶ�Ӧ�ı����\n");
	printf("1.����ڵ�\n");
	printf("2.���ҽڵ�\n");
	printf("3.ɾ���ڵ�\n");
	printf("4.�ݹ��������\n");
	printf("5.�ݹ��������\n");
	printf("6.�ݹ�������\n");
	printf("7.�ǵݹ��������\n");
	printf("8.�ǵݹ��������\n");
	printf("9.�ǵݹ�������\n");
	printf("10.��α���\n");
	printf("11.�˳�����\n");
	printf("=======================\n");
	int num;
	printf("������һ��1-11�����������в���\n");
	scanf_s("%d", &num);
	while (num) {
		if (num > 11 || num < 1) {
			printf("�Ƿ����룬������Ϸ�������\n");
			scanf_s("%d", &num);
			continue;
		}
		else if(num <= 11&&num >= 1) {
			switch (num)
			{

			case 1: {
				int data;
				printf("������Ҫ�������ֵ\n");
				scanf_s("%d", &data);
				BST_insert(*hbst, data);
				break;
			}
			case 2:{
				int data;
				printf("������Ҫ���ҽڵ��Ӧ����ֵ\n");
				scanf_s("%d", &data);
				BST_search(*hbst, data);
				break;
			}
			case 3: {
				int data;
				printf("������Ҫɾ���ڵ��Ӧ��ֵ\n");
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
				printf("���������ڴ����´εĵ���\n");
				break;
			}
			printf("��������һ���Ϸ��������в���\n");
			scanf_s("%d", &num);
		}
	}
	return 0;
}