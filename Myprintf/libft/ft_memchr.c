

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char *str;

	str = s;
	if (n != 0)
	{
		while (n != 0)
		{
			if (*str++ == (unsigned char)c)
				return ((void *)--str);
			n--;
		}
	}
	return (NULL);
}
