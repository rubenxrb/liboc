#include <stdio.h>

#include "new.h"
#include <stdlib.h>

int main ()
{
	void *s1;
	void *s2;

	s1 = new(String, "This is my sample text\n");
	s2 = new(String, "This is another example\n");
	printf("Size of s1: %zu\n", sizeOf(s1));
	if (string_differ(s1, s2))
		printf("strings are diff\n");
	printf("Size of s2: %zu\n", sizeOf(s2));
	delete(s1);
	delete(s2);
	return 0;
}
