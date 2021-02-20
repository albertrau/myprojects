
#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c,
	size_t n)
{
	char	*a;
	char	*b;

	c = (char)c;
	a = (char*)dst;
	b = (char*)src;
	while (n--)
	{
		dst++;
		if ((*a = *b) == c)
			return (dst);
		a++;
		b++;
	}
	return (NULL);
}
