

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char *a;
	unsigned char *b;

	a = (unsigned char*)s1;
	b = (unsigned char*)s2;
	if (n == 0)
		return (0);
	while (--n && *a != '\0' && *b != '\0' && *a == *b)
	{
		a++;
		b++;
	}
	return (*a - *b);
}
