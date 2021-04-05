#include<stdio.h>
#include<stdlib.h>
#include"Stack.h"

/**
 *  @name        : Status initStack(SqStack* s, int size);
 *	@description : initialize an empty stack and set its maximun length
 *	@param		 : s(SqStack),size
 *	@return		 : Status
 *  @notice      : None
 */
Status init_Stack(SqStack* s, int size) {
	s->data = (ElemType*)malloc(sizeof(ElemType));
	if (!s->data) return ERROR;
	else {
		s->size = size;
		s->top = -1;
		return SUCCESS;
	}
}

/**
 *  @name        : Status isEmptyStack(SqStack* s);
 *	@description : judge the stack whether it is empty or not
 *	@param		 : s(SqStack)
 *	@return		 : Status
 *  @notice      : None
 */
Status isEmptyStack(SqStack* s) {
	if (s->top == -1) {
		printf("栈为空\n");
		return SUCCESS;
	}
	else
	{
		printf("栈不为空\n");
		return ERROR;
	}
}

/**
 *  @name        : Status getTopStack(SqStack* s, ElemType *e);
 *	@description : get the top stack value and return to e
 *	@param		 : s(SqStack),e
 *	@return		 : Status
 *  @notice      : None
 */
Status getTopStack(SqStack * s){
	if (s->top == -1) {
		printf("栈为空\n");
		return ERROR;
	}
	else
	{
		ElemType e;
		e = s->data[s->top];
		printf("栈顶元素的值为%d\n", e);
		return SUCCESS;
	}

}

/**
 *  @name        : Status clearStack(SqStack* s);
 *	@description : clear the stack
 *	@param		 : s(SqStack)
 *	@return		 : Status
 *  @notice      : None
 */
Status clearStack(SqStack* s) {
	if (!s) return ERROR;
	else {
		s->top = -1;
		return SUCCESS;
	}
}

/**
 *  @name        : Status destoryStack(SqStack* s);
 *	@description : destory the stack
 *	@param		 : s(SqStack)
 *	@return		 : Status
 *  @notice      : None
 */
Status destoryStack(SqStack* s) {
	{
		free(s->data);
		s->size = 0;
		s->top = -1;
		return SUCCESS;
	}
}

/**
 *  @name        : Status stackLength(SqStack* s, int length);
 *	@description : to figure out the length of stack
 *	@param		 : s(SqStack),length
 *	@return		 : Status
 *  @notice      : None
 */

Status stackLength(SqStack* s) {
	int length = s->top+1;
	if (length == s->size )
	{
		printf("当前栈的长度为%d",length);
		printf("栈已经满了\n");
		return SUCCESS;
	}
	if (length > s->size) return ERROR;
	else {
		printf("当前栈的长度为%d", length);
		printf("栈未满\n");
		return SUCCESS;
	}
}
/**
 *  @name        : Status pushStack(SqStack* s, ElemType data);
 *	@description : push a element whose value is data to top of the stack
 *	@param		 : s(SqStack),data
 *	@return		 : Status
 *  @notice      : None
 */

Status pushStack(SqStack* s, ElemType data) {
	if (s->top == s->size - 1) {
		printf("栈已经满了，不能再入栈了\n");
		return ERROR;
	}
	else
	{
		s->data[++s->top] = data;
		return SUCCESS;
	}
	
}

/**
 *  @name        : Status popStack(SqStack* s, ElemType* data);
 *	@description : pop the top element and return its value to data
 *	@param		 : s(SqStack),data
 *	@return		 : Status
 *  @notice      : None
 */
Status popStack(SqStack* s) {
	if (s->top == -1) {
		printf("栈内无元素\n");
		return ERROR;
	}
	else {
		int output = s->data[s->top];
		s->top--;
		printf("删除的元素为%d\n", output);
		return SUCCESS;
	}
}