

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t		l;

	if (dst == NULL && src == NULL)
		return (0);
	l = ft_strlen(src);
	if (dstsize == 0)
	{
		return (l);
	}
	while (--dstsize && *src != '\0')
	{
		*dst = *src;
		dst++;
		src++;
	}
	*dst = '\0';
	return (l);
}
