#include<stdio.h>

int a[101];
int b[100];

void merge(int l,int m,int h)
{
	int l1,l2,i;
	for(l1=l,l2=m+1,i=l;l1<=m && l2<=h;i++)
	{
		if(a[l1]<=a[l2])
			b[i]=a[l1++];
		else 
		b[i]=a[l2++];
	}
	while(l1<=m)
		b[i++]=a[l1++];
	while(l2<=h)
		b[i++]=a[l2++];

	for(i=l;i<=h;i++)
		a[i]=b[i];
}
void sort(int l,int h)
{
	int m;
	if(l<h)
	{
		m=(l+h)/2;
		sort(l,m);
		sort(m+1,h);
		merge(l,m,h);
	}
	else
		return;
}


int main()
{
	int i,n;
	printf("enter the number of elements\n");
	scanf("%d",&n);
	printf("enter the elements of the array\n");
	n=n-1;
	for(i=0;i<=n;i++)
		scanf("%d",&a[i]);
	printf("\narray after sorting\n");
	sort(0,n);
	for(i=0;i<=n;i++)
		printf("%d\n",a[i]);
}
