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
 *  @name        : int GetDigit(int num, int i);
 *	@description : get the digit of the num
 *	@param		 : num,i
 *	@return		 : int
 *  @notice      : None
 */
int GetDigit(int num, int i); //i为取整数num的位数

 /**
 *  @name        : void RadixSort(int* a, int* c, int len);
 *	@description : sort the array
 *	@param		 : *a,*c,len
 *	@return		 : void
 *  @notice      : None
 */
void RadixSort(int* a, int* c, int len);