/***************************************************************************************
 *	File Name				:	linkStack
 *	CopyRight				:	2021 QG Studio
 *	SYSTEM					:   win10
 *	Create Data				:	2021.4.3
 *
 *
 *--------------------------------Revision History--------------------------------------
 *	No	version		Data			Revised By			Item			Description
 *
 *
 ***************************************************************************************/

 /**************************************************************
*	Multi-Include-Prevent Section
**************************************************************/
#ifndef LINKEDLIST_H_INCLUDED
#define LINKEDLIST_H_INCLUDED
typedef int ElemType;
typedef struct StackNode {
	ElemType data;
	struct StackNode* next;
}StackNode,*LinkStackPtr;

typedef struct	LinkStack {
	LinkStackPtr top;
	int count;
}LinkStack;

typedef enum Status {
	ERROR = 0,
	SUCCESS = 1
} Status;

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
Status initStack(LinkStack* head);

/**
 *  @name        : Status initStack(LinkStack* head);
 *	@description : to get the top element and return its value to data
 *  @param		 : head,data
 *	@return		 : Status
 *  @notice      : None
 */
Status getTopStack(LinkStack* head, ElemType* data);

/**
 *  @name        :Status isEmpty(LinkStack *head);
 *	@description : to judge the linkstack whether it is empty or not
 *  @param		 : head
 *	@return		 : Status
 *  @notice      : None
 */
Status isEmpty(LinkStack *head);

/**
 *  @name        : Status destorylinkstack(LinkStack* head);
 *	@description : destory the stack and exit the program
 *  @param		 : head
 *	@return		 : Status
 *  @notice      : None
 */
Status destorylinkstack(LinkStack* head);

/**
 *  @name        : Status push(LinkStack* head, ElemType data);
 *	@description : add an element whose value is data to the top of linkstack
 *  @param		 : head,data
 *	@return		 : Status
 *  @notice      : None
 */
Status push(LinkStack* head, ElemType data);

/**
 *  @name        : Status pop(LinkStack* head, ElemType *data);
 *	@description : delete the top element and return its value to data
 *  @param		 : head,data
 *	@return		 : Status
 *  @notice      : None
 */
Status pop(LinkStack* head, ElemType *data);

/**
 *  @name        : Status stcakLength(LinkStack* head);
 *	@description : to measure the length of the stack
 *  @param		 : head,length
 *	@return		 : Status
 *  @notice      : None
 */
Status stackLength(LinkStack* head, int length);
#endif