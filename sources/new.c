#include <assert.h>
#include <stdlib.h>
#include "new.h"

/* creates new object using class as reference */
void *new(const void * _class, ...)
{
	const struct Class *class = _class;
	va_list ap;
	void * p = calloc(1, class->size);

	assert(p);
	*(const struct Class **)p = class;

	if (class->ctor)
	{
		va_start(ap, _class);
		p = class -> ctor(p, & ap);
		va_end(ap);
	}
	return p;
}

/* calls the destructor, frees object */
void delete(void *self)
{
	const struct Class **cp = self;

	if (self && * cp && (*cp)->dtor)
		self = (*cp)->dtor(self);
	free(self);
}

/* returns a call to a cloning function on the obj */
void *clone(const void *self)
{
	const struct Class * const *cp = self;

	assert(self && * cp && (*cp) -> clone);
	return (* cp) -> clone(self);
}

/* compares current obj and other data */
int differ(const void *self, const void *b)
{
	const struct Class * const *cp = self;

	assert(self && * cp && (*cp)->differ);
	return (*cp)->differ(self, b);
}

/* returns the size of the current object */
size_t sizeOf(const void *self)
{
	const struct Class * const *cp = self;

	assert(self && *cp);
	return (*cp)->size;
}
