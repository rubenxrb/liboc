/*
 * Set = count keeps track of the number of elements in a set
 * Obj = count records how many times this element as been added to the set,
 * we decrement count each time this element has dropped a set, count == 0
 * removes element from set
 */
 #include <stdlib.h>
 #include <assert.h>

 #include "new.h"
 #include "Set.h"
 #include "Object.h"

 struct Set { unsigned count; };
 struct Object { unsigned count; struct Set * in; };

 static const size_t _Set = sizeof(struct Set);
 static const size_t _Object = sizeof(struct Object);

 const void * Set = & _Set;
 const void * Object = & _Object;

/*
 * constructor always passed to new()
 * allocates and returns new set in heap according to *type's size;
 */
 void * new (const void * type, ...)
 {	const size_t size = * (const size_t *) type;
 	void * p = calloc(1, size);

 	assert(p);
 	return p;
 }

/* frees element */
 void delete (void * item)
 {
 	free(item);
 }

/* element->in points to allocated heap set increases both counts, element's
and set's */
 void * add (void * _set, const void * _element)
 {	struct Set * set = _set;
 	struct Object * element = (void *) _element;

 	assert(set);
 	assert(element);

 	if (! element -> in)
 		element -> in = set;
 	else
 		assert(element -> in == set);
 	++ element -> count, ++ set -> count;

 	return element;
 }

/* checks if element points to the appropiate set */
 void * find (const void * _set, const void * _element)
 {	const struct Object * element = _element;

 	assert(_set);
 	assert(element);

 	return element -> in == _set ? (void *) element : 0;
 }

 int contains (const void * _set, const void * _element)
 {
 	return find(_set, _element) != 0;
 }
/* if element is found, it decrements element's count and # of elements in set
if element's count reaches zero, element is removed from set */
 void * drop (void * _set, const void * _element)
 {	struct Set * set = _set;
 	struct Object * element = find(set, _element);

 	if (element)
 	{	if (-- element -> count == 0)
 			element -> in = 0;
 		-- set -> count;
 	}
 	return element;
 }

/* returns number of elements in set */
 unsigned count (const void * _set)
 {	const struct Set * set = _set;

 	assert(set);
 	return set -> count;
 }

/* returns comparison between pointers */
 int differ (const void * a, const void * b)
 {
 	return a != b;
 }
