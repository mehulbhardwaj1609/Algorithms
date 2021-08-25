#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i,j,n,a[50],count=0;
    printf("\nEnter the size of the array: \n");
    scanf("%d",&n);
    printf("\nEnter %d elements into the array: \n",n);
    for(i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(i=1;i<n;i++)
    {
        for(j=i+1;j<=n;j++)
        {
            if(a[i]>a[j])
                count=count+1;
        }
    }

    printf("\nNo.of Inversions=%d\n",count);
    return 0;
}
