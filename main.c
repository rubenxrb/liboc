#include <stdio.h>

#include "new.h"
#include <stdlib.h>

int main ()
{
	char *str;
	void *obj;

	obj = new(String, "This is my sample text\n");
	str = (char *)clone(obj);
	printf("str = [%s]\n", str);
	delete(obj);
	return 0;
}
