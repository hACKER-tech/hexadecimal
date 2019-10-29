//INPUT  : 2 integers, 'a' and 'base'.
//OUTPUT : Hexadecimal form of 'a' for the base 'base'
#include <stdio.h>
#include<stdlib.h>
int count=0;						//Global variable

char hex(int a, int base, char *output)			//Recursion: Stores the output in the reverse order
{
	if(a>0)
	{
		if(a%base<10)
			*(output+count) = '0'+a%base;	//using ASCII value to store the character
		else
			*(output+count) = 'a'+a%base-10;//using ASCII value to store the character
		count++;
		return hex(a/base, base, output);
	}
}

int main()
{
	int a, base;
	scanf("%d", &a);				//INPUT
	scanf("%d", &base);
	char *output;
	output = (char*)malloc(31*sizeof(char));	//Initialisation of the pointer
	hex(a, base, output);				//Calling the function
	for (int j=count; j>0; j--)			//OUTPUT
		printf("%c", *(output+j-1));
	printf("\n");
	free(output);					//De-allocation
	return 0;
}
