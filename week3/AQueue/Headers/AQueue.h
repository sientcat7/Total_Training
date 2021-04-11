/***************************************************************************************
 *	File Name				:	AQueue.h
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
#define MAXSIZE 100

 /**************************************************************
 *	Struct Define Section
 **************************************************************/

 // define element type
typedef struct SqQueue {
	void *data[MAXSIZE];
	int head;
	int tail;
	int type[MAXSIZE];
}AQueue;

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
Status InitQueue(AQueue*Q);

/**
 *  @name        : Status DestoryQueue(AQueue* Q);
 *	@description : destory a queue
 *	@param		 : Q
 *	@return		 : Status
 *  @notice      : None
 */
Status DestoryQueue(AQueue* Q);

/**
 *  @name        : Status EnQueue(AQueue* Q,void*p);
 *	@description : add the element which value is p to queue
 *	@param		 : Q,p
 *	@return		 : Status
 *  @notice      : None
 */
Status EnQueue(AQueue* Q,void*p);

/**
 *  @name        : Status DeQueue(AQueue* Q);
 *	@description : delete the top value of queue
 *	@param		 : Q
 *	@return		 : Status
 *  @notice      : None
 */
Status DeQueue(AQueue* Q);

/**
 *  @name        : Status ClearQueue(AQueue* Q);
 *	@description : clear all the value of queue
 *	@param		 : Q
 *	@return		 : Status
 *  @notice      : None
 */
Status ClearQueue(AQueue* Q);

/**
 *  @name        : Status GetHeadQueue(AQueue *Q, void *e);
 *	@description : get the top element and return its value to e
 *	@param		 : Q,e
 *	@return		 : Status
 *  @notice      : None
 */
Status GetHeadQueue(AQueue *Q, void *e);

/**
 *  @name        : Status IsFullQueue(AQueue *Q);
 *	@description : judge the queue whether it is full or not
 *	@param		 : Q
 *	@return		 : Status
 *  @notice      : None
 */
Status IsFullQueue(AQueue *Q);

/**
 *  @name        : Status IsEmptyQueue(AQueue *Q);
 *	@description : judge the queue whether it is empty or not
 *	@param		 : Q
 *	@return		 : Status
 *  @notice      : None
 */
Status IsEmptyQueue(AQueue *Q);

/**
 *  @name        : int LengthQueue(AQueue *Q);
 *	@description : return the length of the queue
 *	@param		 : Q
 *	@return		 : int
 *  @notice      : None
 */
int LengthQueue(AQueue *Q);

/**
 *  @name        : Status TraverseQueue(AQueue* Q, void(*foo)(void* q, int typeDate));
 *	@description : traverse the queue and print all the value
 *	@param		 : Q ,foo()
 *	@return		 : Status
 *  @notice      : None
 */
Status TraverseQueue(AQueue* Q, void(*foo)(void* q, int typeDate));

/**
 *  @name        : void foo(void* q, int typeData);
 *	@description : printf the value
 *	@param		 : q,typeData
 *	@return		 : void
 *  @notice      : None
 */
void foo(void* q, int typeData);





