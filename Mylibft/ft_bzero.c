

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	char	*p;
	size_t	i;

	p = s;
	i = 0;
	while (i != n)
	{
		*p = '\0';
		i++;
		p++;
	}
}
