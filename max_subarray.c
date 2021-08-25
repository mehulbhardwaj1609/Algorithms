#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,max,sum=0,s=0,e=0;
    int i,j,k;
    printf("Enter the size of the array: ");
    scanf("%d",&n);
    int a[n];
    printf("Enter %d elements into the array: ",n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    max=a[0];
    for(i=0;i<n;i++)
    {
        sum=0;
        for(j=i;j<n;j++)
        {
            sum=sum+a[j];
            if(sum>max)
            {
                s=i;
                e=j;
                max=sum;
            }
        }
    }
    printf("\nThe largest contigous subarray is: ");
    for(k=s;k<=e;k++)
    {
        printf(" %d ",a[k]);
    }
    printf("\nThe sum of the largest contigous subarray is: ");
    printf(" %d\n",max);
    return 0;
    }

