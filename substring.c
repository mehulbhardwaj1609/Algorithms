#include <stdio.h>
#include <stdlib.h>


int main()
{
	char s[50],a[10];
	int i,j,k;
	printf("enter the source string\n");
	scanf("%s",s);
	printf("enter the pattern string\n");
	scanf("%s",a);
	for(i=0;s[i]!='\0';i++)
	{
		j=0;
		k=i;
		while(a[j]!='\0')
		{
		
			if(s[k]==a[j])
			{
				k++;
				j++;
			}
			else
				break;
		}
		if(a[j]=='\0')
		{
			printf("\npattern found from %d to %d\n",i+1,i+j);
			return 0;
		}
	}
	
	printf("\nfailure\n");
	return 0;
	
}
