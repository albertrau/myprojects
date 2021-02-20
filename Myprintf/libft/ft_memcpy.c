
#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t		i;
	char		*x;
	char		*p;

	i = 0;
	p = (char*)dst;
	x = (char*)src;
	if (dst == NULL && src == NULL)
		return (NULL);
	while (i != n)
	{
		*p = *x;
		p++;
		x++;
		i++;
	}
	return (dst);
}
