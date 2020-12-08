#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "display.h"

int tmp(void *n,int type)
{
	if (type == 1)
	{
		printf("via is %s\n",(char *)n);
	}
	else
	{
		printf("via is %d\n", *(int *)n);
	}
}

int main()
{
	int a = 2;
	char *b = "wmfjkajr";
	tmp(&a,0);
	tmp(b, 1);

	display();
	return 0;
}