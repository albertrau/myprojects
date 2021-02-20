

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*q;

	q = (char*)s;
	i = 0;
	while (q[i] != '\0')
	{
		i++;
	}
	if (q[i] == '\0')
	{
		while (i != 0 && q[i] != c)
		{
			i--;
		}
		if (q[i] == c)
			return (&q[i]);
		return (0);
	}
	return (0);
}
