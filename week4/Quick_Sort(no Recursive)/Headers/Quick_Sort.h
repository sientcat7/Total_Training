/***************************************************************************************
 *	File Name				:	Quick_Sort.c
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
 *  @name        : int partition(int* a, int left, int right);
 *	@description : to get the left value and sort the list
 *	@param		 : *a,left,right
 *	@return		 : int
 *  @notice      : None
 */
int partition(int* a, int left, int right);

/**
*  @name        : void Quick_Sort(int* a, int n);
*	@description : sort the array
*	@param		 : *a,n
*	@return		 : void
*  @notice      : None
*/
void Quick_Sort(int* a, int n);