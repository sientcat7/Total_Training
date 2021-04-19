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

#include<iostream>
#include<stack>
#include"Quick_Sort.h"
using namespace std;
extern void GetAppPath(char* PathName);

/**
*  @name        : int partition(int* a, int left, int right);
*	@description : to get the left value and sort the list
*	@param		 : *a,left,right
*	@return		 : int
*  @notice      : None
*/
int partition(int* a, int left, int right)
{
    int pivot = a[left];
    while (left < right)
    {
        while (left < right && a[right] >= pivot)
            right--;
        a[left] = a[right];
        while (left < right && a[left] <= pivot)
            left++;
        a[right] = a[left];
    }
    a[left] = pivot;
    return left;
}

/**
*  @name        : void Quick_Sort(int* a, int n);
*	@description : sort the array
*	@param		 : *a,n
*	@return		 : void
*  @notice      : None
*/
void Quick_Sort(int* a, int n)
{
    int left = 0;
    int right = n - 1;
    stack<int> s;
    s.push(left);
    s.push(right);
    while (!s.empty())
    {
        right = s.top();
        s.pop();
        left = s.top();
        s.pop();
        int index = partition(a, left, right);
        if (index - 1 > left)
        {
            s.push(left);
            s.push(index - 1);
        }
        if (index + 1 < right)
        {
            s.push(index + 1);
            s.push(right);
        }
    }
}
