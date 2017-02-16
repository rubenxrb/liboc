#if ! defined MANY || MANY < 1
# define MANY	10
/*
 * assert() abort program if assertion is false
 */
# include <assert.h>
# include <stdio.h>
#endif

/*
 * if an object stores no info and if every object belongs to at most one set,
 * we represent each obj and each set as small, unique positive int values
 * used as indices into an array heap[].
 */
static int	heap[MANY];

void	*new_s(const void *type, ...)
{
	int	*p;

	p = heap + 1; /* & heap[1] */
	(void)type;
	while (p < heap + MANY)
		if (!*p++)
			break ;
	assert(p < heap + MANY);
	*p = MANY;
	printf("set created, p = [%p]\n", p);
	return (p);
}

/*
 * prefic names with underscore and only use them to initialize local variables
 * with the desired types and with the appropriate names. sets heap
 */
void	delete(void *_item)
{
	int	*item;

	item = _item;
	if (item)
	{
		assert(item > heap && item < heap + MANY);
		*item = 0;
	}

}

/*
 * we only want to deal with pointers into heap[], and the set should not
 * belong to some other set.
 */
void	*add(void *_set, const void *_element)
{
	int 		*set;
	const int 	*element;

	set = _set;
	element = _element;
	assert(set > heap && set < heap + MANY);
	assert(*set == MANY);
	assert(element > heap && element < heap + MANY);
	if (*element == MANY)
		*(int *)element = set - heap;
	else
		assert(*element == set - heap);
	printf("element [%p] added to set [%p]\n", _element, _set);
	return ((void *)element);
}

/*
 * looks if the set's element contains the proper index for the set
 */
void	*find(const void *_set, const void *_element)
{
	const int	*set;
	const int	*element;

	set = _set;
	element = _element;
	assert(set > heap && set < heap + MANY);
	assert(*set == MANY);
	assert(element > heap && element < heap + MANY);
	assert(*element);
	printf("found element [%p] in set [%p]\n", _element, _set);
	return *element == set - heap ? (void *) element : 0;
}

/*
 * find as true/false value
 */
int 	contains(const void *_set, const void *_element)
{
	printf("contains _set [%p] in _element [%p]?\n", _set, _element);
	return find(_set, _element) != 0;
}

/*
 * if we find element we mark its (newly-dropped) status with MANY
 */
void	*drop(void *_set, const void *_element)
{
	int	*element;

	element = find(_set, _element);
	if (element)
		*element = MANY;
	return element;
}

/*
 *
 */
int		differ(const void *a, const void *b)
{
	return a != b;
}
