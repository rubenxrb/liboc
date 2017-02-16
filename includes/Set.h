#ifndef SET_H
# define SET_H

extern const void	*Set;

/* takes an element, adds it to set, returns whatever was added or already
	present */
void	*add(void *set, const void *element);
/* looks for element in set, returns the found element or null if not */
void	*find(const void *set, const void *element);
/* locates an element, removes it from set, retun removed element */
void	*drop(void *set, const void *element);
/* converts the result of find into a truth value */
int		contains(const void *set, const void *element);
unsigned	count(const void *_set);


#endif
