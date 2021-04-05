/***************************************************************************************
 *	File Name				:	Stack.h
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
#ifndef STACK_H_INCLUDE
#define STACK_H_INCLUDE


/**************************************************************
*	Struct Define Section
**************************************************************/
typedef int ElemType;

typedef enum Status {
	ERROR = 0,
	SUCCESS = 1
} Status;

typedef struct SqStack {
	ElemType *data;
	int top;
	int size;
}SqStack;

/**************************************************************
*	Prototype Declare Section
**************************************************************/

/**
 *  @name        : Status initStack(SqStack* s, int size);
 *	@description : initialize an empty stack and set its maximun length
 *	@param		 : s(SqStack),size
 *	@return		 : Status
 *  @notice      : None
 */
Status init_Stack(SqStack* s, int size);

/**
 *  @name        : Status isEmptyStack(SqStack* s);
 *	@description : judge the stack whether it is empty or not
 *	@param		 : s(SqStack)
 *	@return		 : Status
 *  @notice      : None
 */
Status isEmptyStack(SqStack* s);

/**
 *  @name        : Status getTopStack(SqStack* s, ElemType *e);
 *	@description : get the top stack value and return to e
 *	@param		 : s(SqStack),e
 *	@return		 : Status
 *  @notice      : None
 */
Status getTopStack(SqStack* s);

/**
 *  @name        : Status clearStack(SqStack* s);
 *	@description : clear the stack
 *	@param		 : s(SqStack)
 *	@return		 : Status
 *  @notice      : None
 */
Status clearStack(SqStack* s);

/**
 *  @name        : Status destoryStack(SqStack* s);
 *	@description : destory the stack
 *	@param		 : s(SqStack)
 *	@return		 : Status
 *  @notice      : None
 */
Status destoryStack(SqStack* s);

/**
 *  @name        : Status stackLength(SqStack* s, int length);
 *	@description : to figure out the length of stack
 *	@param		 : s(SqStack),length
 *	@return		 : Status
 *  @notice      : None
 */

Status stackLength(SqStack* s);
/**
 *  @name        : Status pushStack(SqStack* s, ElemType data);
 *	@description : push a element whose value is data to top of the stack
 *	@param		 : s(SqStack),data
 *	@return		 : Status
 *  @notice      : None
 */

Status pushStack(SqStack* s, ElemType data);

/**
 *  @name        : Status popStack(SqStack* s, ElemType* data);
 *	@description : pop the top element and return its value to data
 *	@param		 : s(SqStack),data
 *	@return		 : Status
 *  @notice      : None
 */
Status popStack(SqStack* s);

#endif 

