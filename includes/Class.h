#ifndef CLASS_H
# define CLASS_H

#include <stdlib.h>
#include <stdarg.h>
#include "String.h"
/*
 * class.size = length that new() allocates for the object
 * class.ctor = points to the constructor called by new(), which recieves the
 * allocated area and the rest of the argv list passed to new() originally.
 * class.dtor = points to destructor called by delete(), which recieves the obj
 * to be destroyed.
 * class.clone = points to a copy function which recieves the obj to be copied
 * class.differ = points to function which compares its obj to something else
 */
struct Class
{
	size_t size;
	void *(* ctor) (void *self, va_list *ap);
 	void *(* dtor) (void *self);
	void *(* clone) (const void *self);
	int (*differ) (const void *self, const void *b);
};

#endif
