

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t		i;
	char		*p;
	char		*x;

	i = 0;
	p = (char*)dst;
	x = (char*)src;
	if (dst == NULL && src == NULL)
		return (NULL);
	if ((uintptr_t)x < (uintptr_t)p)
	{
		x = x + (len - 1);
		p = p + (len - 1);
		while (len--)
			*p-- = *x--;
		return (dst);
	}
	if ((uintptr_t)x > (uintptr_t)p)
	{
		while (i++ != len)
			*p++ = *x++;
		return (dst);
	}
	return (dst);
}
