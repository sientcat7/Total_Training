#include "duLinkedList.h"
#include<stdio.h>
#include <windows.h>
#include<malloc.h>

/**
 *  @name        : Status InitList_DuL(DuLinkedList *L)
 *	@description : initialize an empty linked list with only the head node
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status InitList_DuL(DuLinkedList* L) {
	printf("start");
	L = (DuLinkedList)malloc(sizeof(DuLNode));
	printf("keep going");
	(*L)->prior = NULL;
	(*L)->next = NULL;
	printf("successful");
	return SUCCESS;
}

/**
 *  @name        : void DestroyList_DuL(DuLinkedList *L)
 *	@description : destroy a linked list
 *	@param		 : L(the head node)
 *	@return		 : status
 *  @notice      : None
 */
void DestroyList_DuL(DuLinkedList* L) {
	DuLinkedList p = NULL;
	p = (DuLinkedList)malloc(sizeof(DuLNode));
	p = *L;
	while (p) {
		p = *L;
		*L = (*L)->next;
		free(p);
	}
}

/**
 *  @name        : Status InsertBeforeList_DuL(DuLNode *p, LNode *q)
 *	@description : insert node q before node p
 *	@param		 : p, q
 *	@return		 : status
 *  @notice      : None
 */
Status InsertBeforeList_DuL(DuLNode* p, DuLNode* q) {
	if (!p->prior||!p)return ERROR;
	else {
		DuLinkedList s;
		s = p->prior;
		s->next = q;
		q->next = p;
		q->prior = s;
		p->prior = q;
		return SUCCESS;
	}
}
/**
 *  @name        : Status InsertAfterList_DuL(DuLNode *p, DuLNode *q)
 *	@description : insert node q after node p
 *	@param		 : p, q
 *	@return		 : status
 *  @notice      : None
 */
Status InsertAfterList_DuL(DuLNode* p, DuLNode* q) {
	if (!p) return ERROR;
	else
	{
		DuLinkedList r, s;
		s = p->next;
		s->prior = q;
		q->prior = p;
		q->next = s;
		p->next = q;
		return SUCCESS;
	}
}

/**
 *  @name        : Status DeleteList_DuL(DuLNode *p, ElemType *e)
 *	@description : delete the first node after the node p and assign its value to e
 *	@param		 : p, e
 *	@return		 : status
 *  @notice      : None
 */
Status DeleteList_DuL(DuLNode* p, ElemType* e) {
	if (p->next) {
		DuLinkedList q, r;
		q = p->next;
		r = q->next;
		e = q->data;
		free(q);
		p->next = r;
		r->prior = p;
		return SUCCESS;
	}
	else return ERROR;
}

/**
 *  @name        : void TraverseList_DuL(DuLinkedList L, void (*visit)(ElemType e))
 *	@description : traverse the linked list and call the funtion visit
 *	@param		 : L(the head node), visit
 *	@return		 : Status
 *  @notice      : None
 */
void TraverseList_DuL(DuLinkedList L, void (*visit)(ElemType e)) {
	L = L->next;
	while (L->next) {
		visit(L->data);
		L = L->next;
	}
}

/**
 *  @name        : void visit(ElemType e)
 *	@description : printf the value of node
 *	@param		 : ElemTpye(the value of the node)
 *	@return		 : void
 *  @notice      : None
 */
void visit(ElemType e) {
	printf("%d", e);
}
