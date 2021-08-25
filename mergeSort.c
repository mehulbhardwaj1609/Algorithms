#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>
void fnGenRandInput(int [], int);
void fnDispArray( int [], int);
void fnMerge(int [], int ,int ,int);
void fnMergeSort(int [], int , int);
int main( int argc, char **argv)
{
FILE *fp;
struct timeval tv;
double dStart,dEnd;
int iaArr[500000],iNum,iPos,iKey,i,iChoice;
for(;;)
{
printf("\n1.Plot the Graph\n2.MergeSort\n3.Exit");
printf("\nEnter your choice\n");
scanf("%d",&iChoice);
switch(iChoice)
{
case 1:
fp = fopen("MergePlot.dat","w");
for(i=100;i<100000;i+=100)
{
fnGenRandInput(iaArr,i);
gettimeofday(&tv,NULL);
dStart = tv.tv_sec + (tv.tv_usec/1000000.0);
fnMergeSort(iaArr,0,i-1);
gettimeofday(&tv,NULL);
dEnd = tv.tv_sec + (tv.tv_usec/1000000.0);
fprintf(fp,"%d\t%lf\n",i,dEnd-dStart);
}
fclose(fp);
printf("\nData File generated and stored in file < MergePlot.dat >.\n Use a plotting utility\n");
break;
case 2:
printf("\nEnter the number of elements to sort\n");
scanf("%d",&iNum);
printf("\nUnsorted Array\n");
fnGenRandInput(iaArr,iNum);
fnDispArray(iaArr,iNum);
fnMergeSort(iaArr,0,iNum-1);
printf("\nSorted Array\n");
fnDispArray(iaArr,iNum);
break;
case 3:
exit(0);
}
}
return 0;
}
void fnMerge(int a[], int low,int mid,int high)
{
int i,k,j,b[500000];
i=k=low;
j=mid+1;
while(i<=mid && j<=high)
{
if(a[i]<a[j])
b[k++]=a[i++];
else
b[k++]=a[j++];
}
while(i<=mid)
b[k++]=a[i++];
while(j<=high)
b[k++]=a[j++];
for(i=low;i<k;i++)
a[i]=b[i];
}
void fnMergeSort(int a[],int low,int high)
{
int mid;
if(low<high)
{
mid=(low+high)/2;
fnMergeSort(a,low,mid);
fnMergeSort(a,mid+1,high);
fnMerge(a,low,mid,high);
}
}
void fnGenRandInput(int X[], int n)
{
int i;
srand(time(NULL));
for(i=0;i<n;i++)
{
X[i] = rand()%10000;
}
}
void fnDispArray( int X[], int n)
{
int i;
for(i=0;i<n;i++)
printf(" %5d \n",X[i]);
}
