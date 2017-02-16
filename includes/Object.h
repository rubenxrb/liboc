#ifndef OBJECT_H
# define OBJECT_H

/* if an object is member of a set, its array element contains the integer value
representing the set. Objects point to the set containing them. Objects do not
belong in more than 1 set. */
extern const void	*Object; /* new(Object); */

/* can compare objects: returns true if they are not equal */
int		differ(const void *a, const void *b);

#endif
