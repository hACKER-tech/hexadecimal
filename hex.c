#include <stdio.h>
#include<stdlib.h>
int count=0;					

char hex(int a, char *output)	
{
	if(a>0)
	{
		if(a%16<10)
			*(output+count) = '0'+a%16;
		else
			*(output+count) = 'a'+a%16-10;
		count++;
		return hex(a/16, output);
	}
}

int main()
{
	int a;
	scanf("%d", &a);	
	char *output;
	output = (char*)malloc(31*sizeof(char));
	hex(a, output);	
	for (int j=count; j>0; j--)	
		printf("%c", *(output+j-1));
	printf("\n");
	free(output);
	return 0;
}
