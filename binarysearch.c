#include<stdio.h>
int fnBinSearch(int A[], int k, int iLow,int iHigh);
int main(void)
{
int iaArr[20],iNum,iKey;
int i,iPos=0;
printf("\nEnter the size of the array\n");
scanf("%d",&iNum);
printf("\nEnter the elements of the array in ascending order:\n");
for(i=0;i<iNum;i++)
scanf("%d",&iaArr[i]);
printf("\nenter the key element\n");
scanf("%d",&iKey);
iPos=fnBinSearch(iaArr,iKey,0,iNum-1);
if(iPos==-1)
printf("\nElement not found\n");
else
printf("\nElement found at position %d\n",iPos+1);
return 0;
}
int fnBinSearch(int A[], int k, int iLow,int iHigh)
{
int iMid;
if(iLow<=iHigh)
{
iMid=(iLow+iHigh)/2;
if(k==A[iMid])
return iMid;
if(k<A[iMid])
return fnBinSearch(A,k,iLow,iMid-1);
if(k>A[iMid])
return fnBinSearch(A,k,iMid+1,iHigh);
}
else
return -1;
}
