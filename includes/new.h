#ifndef NEW_H
# define NEW_H

# include "Class.h"
/* creates new object using class as reference */
void	*new(const void *class, ...);
/* accepts pointer produced by new() and recycles assoicated resources */
void	delete(void *item);
void	*clone(const void *self);
int		differ(const void *self, const void *b);
size_t	sizeOf(const void *self);

#endif
