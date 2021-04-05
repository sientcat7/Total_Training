#include<stdio.h>
#include<stdlib.h>
#include"linkStack.h"

/**************************************************************
*	Prototype Declare Section
**************************************************************/

/**
 *  @name        : Status initStack(LinkStack* head);
 *	@description : initialize an empty stack
 *  @param		 : head
 *	@return		 : Status
 *  @notice      : None
 */
Status initStack(LinkStack* head) {
	head->top = (LinkStackPtr)malloc(sizeof(StackNode));
	if (head->top == NULL) {
		printf("��ʼ��ʧ����\n");
		return ERROR;
	}
	else {
		head->count = 0;
		head->top->next = NULL;
		printf("��ʼ���ɹ�\n");
		return SUCCESS;
	}
}

/**
 *  @name        : Status getTopStack(LinkStack* head, ElemType* data)
 *	@description : to get the top element and return its value to data
 *  @param		 : head,data
 *	@return		 : Status
 *  @notice      : None
 */
Status getTopStack(LinkStack* head, ElemType* data) {
	if (!head->top) {
		printf("ջΪ��\n");
		return ERROR;
	}
	else {
		*data = head->top->data;
		printf("ջ����Ԫ�ص�ֵ%d\n",*data);
		return SUCCESS;
	}
}

/**
 *  @name        : Status isEmpty(LinkStack *head);
 *	@description : to judge the linkstack whether it is empty or not
 *  @param		 : head
 *	@return		 : Status
 *  @notice      : None
 */
Status isEmpty(LinkStack* head) {
	if (head->top == NULL) {
		printf("��ǰջΪ��\n");
		return SUCCESS;
	}
	else {
		printf("��ǰջ��Ϊ��\n");
		return ERROR;
	}
}

/**
 *  @name        : Status destorylinkstack(LinkStack* head);
 *	@description : destory the stack and exit the program
 *  @param		 : head
 *	@return		 : Status
 *  @notice      : None
 */
Status destorylinkstack(LinkStack* head) {
	StackNode* s = head->top;
	if (!head->top) return ERROR;
	while(head->top){
		head->top = head->top->next;
		free(s);
		s = head->top;
	}
	printf("��ջ�Ѿ�����\n");
	return SUCCESS;
}

/**
 *  @name        : Status push(LinkStack* head, ElemType data);
 *	@description : add an element whose value is data to the top of linkstack
 *  @param		 : head,data
 *	@return		 : Status
 *  @notice      : None
 */
Status push(LinkStack* head, ElemType data) {
	LinkStackPtr p = (LinkStackPtr)malloc(sizeof(StackNode));
	if (!p) {
		printf("����ջ��Ԫ��ʧ��\n");
		return ERROR;
	}
	if (head->top->next == NULL) {
		head->top->data = data;
		printf("Ԫ����ջ�ɹ�\n");
		head->count++;
		return SUCCESS;
	}
	else {
		p->data = data;
		p->next = head->top;
		head->top = p;
		head->count++;
		printf("Ԫ����ջ�ɹ�\n");
		return SUCCESS;
	}
}

/**
 *  @name        : Status pop(LinkStack* head, ElemType *data);
 *	@description : delete the top element and return its value to data
 *  @param		 : head,data
 *	@return		 : Status
 *  @notice      : None
 */
Status pop(LinkStack* head, ElemType* data) {
	if (head->top == NULL) {
		printf("��ǰջΪ��\n");
		return ERROR;
	}
	else {
		LinkStackPtr p;
		p = (LinkStackPtr)malloc(sizeof(StackNode));
		*data = head->top->data;
		p = head->top;
		head->top = head->top->next;
		free(p);
		head->count--;
		printf("ɾ����ջ��Ԫ�ص�ֵΪ%d\n", *data);
		return SUCCESS;
	}
}

/**
 *  @name        : Status stcakLength(LinkStack* head);
 *	@description : to measure the length of the stack
 *  @param		 : head,length
 *	@return		 : Status
 *  @notice      : None
 */
Status stackLength(LinkStack* head,int length) {
	length = head->count;
	if (head->top == NULL) {
		printf("��ǰջΪ��\n");
		printf("ջ�ĳ���Ϊ%d\n", length);
		return ERROR;
	}
	else {
		printf("ջ�ĳ���Ϊ%d\n", length);
		return SUCCESS;
	}
}
