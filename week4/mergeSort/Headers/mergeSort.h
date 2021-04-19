/***************************************************************************************
 *	File Name				:	mergeSort.h
 *	CopyRight				:	2021 QG Studio
 *	SYSTEM					:   win10
 *	Create Data				:	2021.4.17
 *
 *
 *--------------------------------Revision History--------------------------------------
 *	No	version		Data			Revised By			Item			Description
 *
 *
 ***************************************************************************************/

 /**
 *  @name        : void merge(int *a,int start ,int mid,int end,int len);
 *	@description : sort the array
 *	@param		 : *a,start,mid,end,len
 *	@return		 : void
 *  @notice      : None
 */
void merge(int *a,int start ,int mid,int end,int len);

/**
*  @name        : void mergeSort(int* a, int start, int end,int len);
*	@description : Recursive division of midpoints
*	@param		 : *a,start,end,len
*	@return		 : void
*  @notice      : None
*/
void mergeSort(int* a, int start, int end,int len);