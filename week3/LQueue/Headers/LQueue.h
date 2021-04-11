/***************************************************************************************
 *	File Name				:	LQueue.h
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

 /**************************************************************
 *	Macro Define Section
 **************************************************************/

#define OVERFLOW -1

 /**************************************************************
 *	Struct Define Section
 **************************************************************/
typedef struct QNode {
	int typeData;
	void* data;
	struct QNode* next;
}QNode,*QueuePtr;

typedef struct LinkQueue {
	QueuePtr head;
	QueuePtr tail;
}LinkQueue;

typedef enum Status {
	ERROR = 0,
	SUCCESS = 1,
} Status;

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
Status InitQueue(LinkQueue* Q);

/**
 *  @name        : Status DestoryQueue(AQueue* Q);
 *	@description : destory a queue
 *	@param		 : Q
 *	@return		 : Status
 *  @notice      : None
 */
Status DestoryQueue(LinkQueue* Q);

/**
 *  @name        : Status ClearQueue(AQueue* Q);
 *	@description : clear all the value of queue
 *	@param		 : Q
 *	@return		 : Status
 *  @notice      : None
 */
Status ClearQueue(LinkQueue* Q);

/**
 *  @name        : Status IsEmptyQueue(AQueue *Q);
 *	@description : judge the queue whether it is empty or not
 *	@param		 : Q
 *	@return		 : Status
 *  @notice      : None
 */
Status IsEmptyQueue(LinkQueue *Q);

/**
 *  @name        : int LengthQueue(AQueue *Q);
 *	@description : return the length of the queue
 *	@param		 : Q
 *	@return		 : int
 *  @notice      : None
 */
int LengthQueue(LinkQueue *Q);

/**
 *  @name        : Status EnQueue(AQueue* Q,void*p);
 *	@description : add the element which value is p to queue
 *	@param		 : Q,p
 *	@return		 : Status
 *  @notice      : None
 */
Status EnQueue(LinkQueue* Q, void* data);

/**
 *  @name        : Status DeQueue(AQueue* Q);
 *	@description : delete the top value of queue
 *	@param		 : Q
 *	@return		 : Status
 *  @notice      : None
 */
Status DeQueue(LinkQueue* Q);

/**
 *  @name        : Status GetHeadQueue(AQueue *Q, void *e);
 *	@description : get the top element and return its value to e
 *	@param		 : Q,e
 *	@return		 : Status
 *  @notice      : None
 */
Status GetHeadQueue(LinkQueue *Q);

/**
 *  @name        : Status TraverseQueue(AQueue* Q, void(*foo)(void* q, int typeDate));
 *	@description : traverse the queue and print all the value
 *	@param		 : Q ,foo()
 *	@return		 : Status
 *  @notice      : None
 */
Status TraverseQueue(LinkQueue* Q, void(*foo)(void* q, int typeDate));

/**
 *  @name        : void foo(void* q, int typeData);
 *	@description : printf the value
 *	@param		 : q,typeData
 *	@return		 : void
 *  @notice      : None
 */
void foo(void* q, int typeData);
