#include<stdio.h>
#include"dulinkedList.h"

int main(void) {
	printf("��������Ӧ����ĸ���в�ͬ�Ĺ��ܣ�����Ϊ���ܱ�\n");
	printf("a.����ͷ�ڵ�\nb.����ڵ㣬ͷ�巨\nc,����ڵ㣬β�巨\nd.ɾ�������ڵ㣬������ɾ���ڵ��Ӧ����ֵ\n");
	printf("e.������������ӡ�����ֵ\nf.ɾ����������demo\n");
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