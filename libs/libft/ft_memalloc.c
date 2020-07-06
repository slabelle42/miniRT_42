#include "libft.h"

void	*ft_memalloc(size_t size)
{
	char	*alloc;
	
	if (!(alloc = malloc(sizeof(void) * size)))
		return (NULL);
	ft_memset(alloc, 0, size);
	return (alloc);
}
