#include <stdio.h> 
#include <stdlib.h> 


int main(int argc ,char *argv[]) 
{
	int a = 0x12345678;
	char *p = &a;
	p++;
	printf("%x\n",*p ); //high: 12 low: 78

	return 0; 
}
