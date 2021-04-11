/***************************************************************************************
 *	File Name				:	AQueue.c
 *	CopyRight				:	2021 QG Studio
 *	SYSTEM					:   win10
 *	Create Data				:	2021.4.11
 *
 *
 *--------------------------------Revision History--------------------------------------
 *	No	version		Data			Revised By			Item			Description
 *
 *
 ***************************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include <string.h>

#include"AQueue.h"

 /**
  *  @name        : Status InitQueue(AQueue*Q);
  *	@description : initialize an empty queue
  *	@param		 : Q
  *	@return		 : Status
  *  @notice      : None
  */
Status InitQueue(AQueue* Q) {
	if (!Q) {
		printf("初始化失败\n");
		return ERROR;
	}
	else {
		Q->head = 0;
		Q->tail = 0;
		for (int i = 0; i < MAXSIZE; i++)
			Q->data[i] = (void*)malloc(21);
		printf("初始化成功\n");
		return SUCCESS;
	}
}

/**
 *  @name        : Status DestoryQueue(AQueue* Q);
 *	@description : destory a queue
 *	@param		 : Q
 *	@return		 : Status
 *  @notice      : None
 */
Status DestoryQueue(AQueue* Q) {
	if (Q->data[0] == NULL) {
		printf("队列还没有初始化，请先初始化在进行该操作\n");
		return ERROR;
	}
	else {
		free(Q->data);
		Q->head = Q->tail = 0;
		return SUCCESS;
	}
}

/**
 *  @name        : Status EnQueue(AQueue* Q,void*p);
 *	@description : add the element which value is p to queue
 *	@param		 : Q,p
 *	@return		 : Status
 *  @notice      : None
 */
Status EnQueue(AQueue* Q,void*data) {
	if ((Q->tail + 1) % MAXSIZE == Q->head ) {
		printf("队列已满\n");
		return ERROR;
	}
	else if (Q->data[0] == NULL) {
		printf("队列还没有初始化，请初始化后在进行该操作\n");
		return ERROR;
	}
	else {
		if (Q->head == Q->tail) {
			memcpy(Q->data[Q->head], data, 20);
			Q->tail = (Q->tail + 1) % MAXSIZE;
			printf("新元素入队列成功\n");
			return SUCCESS;
		}
		else {
			memcpy(Q->data[Q->tail], data, 20);
			printf("新元素入队列成功\n");
			return SUCCESS;
		}
	}
}

/**
 *  @name        : Status DeQueue(AQueue* Q);
 *	@description : delete the top value of queue
 *	@param		 : Q
 *	@return		 : Status
 *  @notice      : None
 */
Status DeQueue(AQueue* Q) {
	if (Q->head == Q->tail) {
		printf("队列为空\n");
		return ERROR;
	}
	else if (Q->data[0] == NULL) {
		printf("队列还没有初始化，请初始化后在进行该操作\n");
		return ERROR;
	}
	else {
		Q->head = (Q->head + 1) % MAXSIZE;
		printf("元素出列成功\n");
		return SUCCESS;
	}
}

/**
 *  @name        : Status ClearQueue(AQueue* Q);
 *	@description : clear all the value of queue
 *	@param		 : Q
 *	@return		 : Status
 *  @notice      : None
 */
Status ClearQueue(AQueue* Q) {
	if (Q->head == Q->tail) {
		printf("队列为空\n");
		return ERROR;
	}
	else if (Q->data[0] == NULL) {
		printf("队列还没有初始化，请初始化后在进行该操作\n");
		return ERROR;
	}
	else {
		Q->head = Q->tail = 0;
		printf("队列清空完成\n");
		return SUCCESS;
	}
}

/**
 *  @name        : Status GetHeadQueue(AQueue *Q, void *e);
 *	@description : get the top element and return its value to e
 *	@param		 : Q,e
 *	@return		 : Status
 *  @notice      : None
 */
Status GetHeadQueue(AQueue *Q, void *e) {
	if (Q->head == Q->tail) {
		printf("队列为空\n");
		return ERROR;
	}
	else if (Q->data[0] == NULL) {
		printf("队列还没有初始化，请先初始化在进行该操作\n");
		return ERROR;
	}
	else {
		e = Q->data[Q->tail];
		if (Q->type[Q->tail] == 1) printf("-->%d", *(int*)e);
		if (Q->type[Q->tail] == 2) printf("-->%c", *(char*)e);
		if (Q->type[Q->tail] == 3) printf("-->%lf", *(double*)e);
		if (Q->type[Q->tail] == 4) printf("-->%s", *(char*)e);
		return SUCCESS;

	}
}

/**
 *  @name        : Status IsFullQueue(AQueue *Q);
 *	@description : judge the queue whether it is full or not
 *	@param		 : Q
 *	@return		 : Status
 *  @notice      : None
 */
Status IsFullQueue(AQueue *Q) {
	if (Q->tail - Q->head == MAXSIZE - 1) {
		printf("队列已经满了\n");
		return SUCCESS;
	}
	else if (Q->data[0] == NULL) {
		printf("队列还没有初始化，请先初始化在进行该操作\n");
		return ERROR;
	}
	else {
		printf("队列未满\n");
		return ERROR;
	}
}

/**
 *  @name        : Status IsEmptyQueue(AQueue *Q);
 *	@description : judge the queue whether it is empty or not
 *	@param		 : Q
 *	@return		 : Status
 *  @notice      : None
 */
Status IsEmptyQueue(AQueue *Q) {
	if (Q->head == Q->tail) {
		printf("队列为空\n");
		return SUCCESS;
	}
	else if (Q->data[0] == NULL) {
			printf("队列还没有初始化，请先初始化在进行该操作\n");
			return ERROR;
	}
	else {
		printf("队列不为空\n");
		return ERROR;
	}
}

/**
 *  @name        : int LengthQueue(AQueue *Q);
 *	@description : return the length of the queue
 *	@param		 : Q
 *	@return		 : int
 *  @notice      : None
 */
Status LengthQueue(AQueue *Q) {
	if (Q->data[0] == NULL) {
		printf("队列还没有初始化，请先初始化在进行该操作\n");
		return ERROR;
	}
	else {
		printf("队列当前的长度为%d\n", (Q->tail - Q->head + MAXSIZE) % MAXSIZE);
		return SUCCESS;
	}
}

/**
 *  @name        : Status TraverseQueue(AQueue* Q, void(*foo)(void* q, int typeDate));
 *	@description : traverse the queue and print all the value
 *	@param		 : Q ,foo()
 *	@return		 : Status
 *  @notice      : None
 */
Status TraverseQueue(AQueue* Q, void(*foo)(void* q, int typeDate)) {
	if (Q->data[0] == NULL) {
		printf("队列还没有初始化，请先初始化在进行该操作\n");
		return ERROR;
	}
	else if (Q->head == Q->tail) {
		printf("队列为空\n");
		return ERROR;
	}
	else {
		int i = 0;
		while (i < ((Q->tail - Q->head + MAXSIZE) % MAXSIZE)) {
			foo(Q->data[Q->head + i], Q->type[Q->head + i]);
			i = (i + 1) % MAXSIZE;
		}
		return SUCCESS;
	}

/**
 *  @name        : void foo(void* q, int typeData);
 *	@description : printf the value
 *	@param		 : q,typeData
 *	@return		 : void
 *  @notice      : None
 */
}void foo(void* q, int typeData) {
	if (typeData == 1) printf("-->%d\n", *(int*)q);
	if (typeData == 2) printf("-->%c\n", *(char*)q);
	if (typeData == 3) printf("-->%lf\n", *(double*)q);
}