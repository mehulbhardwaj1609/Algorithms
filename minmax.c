#include <stdio.h>
#include <stdlib.h>

void fnRecMaxMin( int [],int,int,int*,int*);

int main(int argc,char **argv)
{
    int iaArr[500000],iNum,i;
    int iMax=0,iMin=0;
    printf("\nEnter the size of the array: \n");
    scanf("%d",&iNum);
    printf("\nEnter the elements of the array:\n");
    for(i=0;i<iNum;i++)
        scanf("%d",&iaArr[i]);
    fnRecMaxMin(iaArr,0,iNum-1,&iMax,&iMin);
    printf("\nMax element = %d\nMin element = %d\n",iMax,iMin);
    return 0;
}

void fnRecMaxMin(int a[],int low,int high,int *max,int *min)
{
    int mid,max1,max2,min1,min2;
    if(high-low==1)
    {
        if(a[low]>a[high])
        {
            *max=a[low];
            *min=a[high];
        }
        else
        {
            *max=a[high];
            *min=a[low];
        }
    }
    else if(low==high)
    {
        *min=*max=a[low];
    }
    else if(low<high)
    {
        mid=(low+high)/2;
        fnRecMaxMin(a,low,mid,&max1,&min1);
        fnRecMaxMin(a,mid+1,high,&max2,&min2);
        if(max1>max2)
            *max=max1;
        else
            *max=max2;
        if(min1<min2)
            *min=min1;
        else
            *min=min2;
    }
}


