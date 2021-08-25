#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>
void fnGenRandInput(int [], int);
void fnDispArray( int [], int);
void fnMaxHeapify(int[],int,int);
void fnBuildMaxHeap(int[],int);
void fnHeapSort(int[],int);

int main(void)
{
FILE *fp;
struct timeval tv;
double dStart,dEnd;
int iaArr[500000],iNum,iPos,iKey,i,iChoice;
for(;;)
{
printf("\n1.Plot the Graph\n2.HeapSort\n3.Exit");
printf("\nEnter your choice\n");
scanf("%d",&iChoice);
switch(iChoice)
{
case 1:
fp = fopen("HeapPlot.dat","w");
for(i=100;i<100000;i+=100)
{
fnGenRandInput(iaArr,i);
gettimeofday(&tv,NULL);
dStart = tv.tv_sec + (tv.tv_usec/1000000.0);
fnHeapSort(iaArr,i);

gettimeofday(&tv,NULL);
dEnd = tv.tv_sec + (tv.tv_usec/1000000.0);
fprintf(fp,"%d\t%lf\n",i,dEnd-dStart);
}
fclose(fp);
printf("\nData File generated and stored in file < HeapPlot.dat>.\n Use a plotting utility\n");
break;
case 2:
printf("\nEnter the number of elements to sort\n");
scanf("%d",&iNum);
printf("\nUnsorted Array\n");
fnGenRandInput(iaArr,iNum);
fnDispArray(iaArr,iNum);
fnHeapSort(iaArr,iNum);
printf("\nSorted Array\n");
fnDispArray(iaArr,iNum);
break;
case 3:
exit(0);
}
}
return 0;
}

void fnMaxHeapify(int a[],int i,int n)
{
int l,r,largest,temp;
l=2*i;
r=(2*i)+1;
if((l<=n)&& (a[l]>a[i]))
{
largest=l;
}
else
largest=i;
if((r<=n)&&(a[r]>a[largest]))
largest=r;
if(largest!=i)
{
temp=a[i];
a[i]=a[largest];
a[largest]=temp;
fnMaxHeapify(a,largest,n);

}
}

void fnBuildMaxHeap(int a[],int n)
{
int i;
for(i=n/2;i>=1;i--)
fnMaxHeapify(a,i,n);
}

void fnHeapSort(int a[],int n)
{
int temp,i;
fnBuildMaxHeap(a,n);
for(i=n;i>=2;i--)
{
temp=a[1];
a[1]=a[i];
a[i]=temp;
fnMaxHeapify(a,1,i-1);
}
}

void fnGenRandInput(int X[], int n)
{
int i;
srand(time(NULL));
for(i=1;i<=n;i++)
{
X[i] = rand()%10000;
}
}

void fnDispArray( int X[], int n)
{
int i;
for(i=1;i<=n;i++)
printf(" %5d \n",X[i]);
}


