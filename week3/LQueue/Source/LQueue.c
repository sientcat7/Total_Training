
/***************************************************************************************
 *	File Name				:	LQueue.c
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

#include"LQueue.h"

 /**************************************************************
 *	Prototype Declare Section
 **************************************************************/

 /**
  *  @name        : Status InitQueue(AQueue*Q);
  *	@description : initialize an empty queue
  *	@param		 : Q
  *	@return		 : Status
  *  @notice      : None
  */
Status InitQueue(LinkQueue* Q) {
	Q->head = Q->tail = (QueuePtr)malloc(sizeof(QNode));
	if (Q->head == NULL || Q->tail == NULL) {
		printf("初始化失败\n");
		return ERROR;
	}
	else {
		Q->tail->next = NULL;
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
Status DestoryQueue(LinkQueue* Q) {
	if (Q->head == NULL || Q->tail == NULL) {
		printf("该队列还没有初始化，请先进行初始化操作\n");
		return ERROR;
	}
	else {
		while (Q->head) {
			Q->tail = Q->head->next;
			free(Q->head);
			Q->head = Q->tail;
		}
		printf("队列销毁成功\n");
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
Status ClearQueue(LinkQueue* Q) {
	if (Q->head == NULL || Q->tail == NULL) {
		printf("该队列还没有初始化，请先进行初始化操作\n");
		return ERROR;
	}
	else {
		QueuePtr temp;
		Q->tail = Q->head->next;
		while (Q->tail) {
			temp = Q->tail->next;
			free(Q->tail);
			Q->tail = temp;
		}
		Q->tail = Q->head;
		printf("队列清除完成\n");
		return SUCCESS;
	}
}

/**
 *  @name        : Status IsEmptyQueue(AQueue *Q);
 *	@description : judge the queue whether it is empty or not
 *	@param		 : Q
 *	@return		 : Status
 *  @notice      : None
 */
Status IsEmptyQueue(LinkQueue *Q) {
	if (Q->head == NULL || Q->tail == NULL) {
		printf("该队列还没有初始化，请先进行初始化操作\n");
		return ERROR;
	}
	else if (Q->head == Q->tail && Q->head != NULL) {
		printf("队列为空\n");
		return SUCCESS;
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
int LengthQueue(LinkQueue *Q) {
	if (Q->head == NULL || Q->tail == NULL) {
		printf("该队列还没有初始化，请先进行初始化操作\n");
		return ERROR;
	}
	else {
		QueuePtr temp;
		int count = 0;
		temp = Q->head->next;
		while (temp != NULL) {
			++count;
			temp = temp->next;
		}
		printf("队列当前的长度为%d\n", count);
		return 1;
	}
}

/**
 *  @name        : Status DeQueue(AQueue* Q);
 *	@description : delete the top value of queue
 *	@param		 : Q
 *	@return		 : Status
 *  @notice      : None
 */
Status DeQueue(LinkQueue* Q) {
	if (Q->head == NULL || Q->tail == NULL) {
		printf("该队列还没有初始化，请先进行初始化操作\n");
		return ERROR;
	}
	else if (Q->head == Q->tail) {
		printf("队列当前为空\n");
		return ERROR;
	}
	else {
		QueuePtr temp = (QueuePtr)malloc(sizeof(QNode));
		temp = Q->head->next;
		Q->head->next = temp->next;
		if (Q->tail == temp) Q->head = Q->tail;
		free(temp);
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
Status GetHeadQueue(LinkQueue* Q,void*e) {
	if (Q->head == NULL || Q->tail == NULL) {
		printf("该队列还没有初始化，请先进行初始化操作\n");
		return ERROR;
	}
	else if (Q->head == Q->tail) {
		printf("队列当前为空\n");
		return ERROR;
	}
	else {
		e = Q->tail->data;
		if (Q->tail->typeData == 1) printf("-->%d\n", *(int*)e);
		if (Q->tail->typeData == 2) printf("-->%c\n", *(char*)e);
		if (Q->tail->typeData == 3) printf("-->%lf\n", *(double*)e);
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
Status EnQueue(LinkQueue* Q, void* data,int t) {
	if (Q->head == NULL || Q->tail == NULL) {
		printf("该队列还没有初始化，请先进行初始化操作\n");
		return ERROR;
	}
	else {
		QueuePtr temp = (QueuePtr)malloc(sizeof(QNode));
		temp->data = data;
		if (t == 1) temp->typeData = 1;
		if (t == 2) temp->typeData = 2;
		if (t == 3) temp->typeData = 3;
		temp->next = NULL;
		Q->tail->next = temp;
		Q->tail = temp;
		printf("新元素入列成功\n");
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
Status TraverseQueue(LinkQueue* Q, void(*foo)(void* q, int typeDate)) {
	if (Q->head == NULL || Q->tail == NULL) {
		printf("该队列还没有初始化，请先进行初始化操作\n");
		return ERROR;
	}
	else if (Q->head == Q->tail) {
		printf("队列当前为空\n");
		return ERROR;
	}
	else {
		int i = 0;
		QueuePtr temp = (QueuePtr)malloc(sizeof(QNode));
		temp = Q->head->next;
		while (!temp) {
			foo(temp->data,temp->typeData);
			temp = temp->next;
			
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