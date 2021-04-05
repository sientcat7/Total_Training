#include<stdio.h>
#include"dulinkedList.h"

int main(void) {
	printf("请输入相应的字母进行不同的功能，如下为功能表\n");
	printf("a.创建头节点\nb.插入节点，头插法\nc,插入节点，尾插法\nd.删除单个节点，并返回删除节点对应的数值\n");
	printf("e.遍历链表，并打印链表的值\nf.删除链表，结束demo\n");
	char n;
	DuLinkedList L = NULL;
	while ( n = getchar()) {
		switch (n) {
		case'a':InitList_DuL(L); break;
		case'b':break;
		case'c':break;
		case'd':break;
		case'e':TraverseList_DuL(L,&visit); break;
		default:DestroyList_DuL(L);
		}
		if (n != 'f') continue;
	}
}