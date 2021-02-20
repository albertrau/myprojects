#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	char	*p;
	size_t	i;

	c = (unsigned char)c;
	p = s;
	i = 0;
	while (i != n)
	{
		i++;
		*p = c;
		p++;
	}
	return (s);
}
