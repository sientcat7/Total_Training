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
		printf("初始化失败了\n");
		return ERROR;
	}
	else {
		head->count = 0;
		head->top->next = NULL;
		printf("初始化成功\n");
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
		printf("栈为空\n");
		return ERROR;
	}
	else {
		*data = head->top->data;
		printf("栈顶的元素的值%d\n",*data);
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
		printf("当前栈为空\n");
		return SUCCESS;
	}
	else {
		printf("当前栈不为空\n");
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
	printf("链栈已经销毁\n");
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
		printf("加入栈顶元素失败\n");
		return ERROR;
	}
	if (head->top->next == NULL) {
		head->top->data = data;
		printf("元素入栈成功\n");
		head->count++;
		return SUCCESS;
	}
	else {
		p->data = data;
		p->next = head->top;
		head->top = p;
		head->count++;
		printf("元素入栈成功\n");
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
		printf("当前栈为空\n");
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
		printf("删除的栈顶元素的值为%d\n", *data);
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
		printf("当前栈为空\n");
		printf("栈的长度为%d\n", length);
		return ERROR;
	}
	else {
		printf("栈的长度为%d\n", length);
		return SUCCESS;
	}
}
