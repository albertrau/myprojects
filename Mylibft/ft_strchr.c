

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char *q;

	q = (char*)s;
	while (*q && *q != c)
		q++;
	if (*q == c)
		return (q);
	return (0);
}
