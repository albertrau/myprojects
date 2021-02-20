

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dsti;
	size_t	srci;

	dsti = 0;
	srci = 0;
	while (dst[dsti] != '\0' && dsti < size)
		dsti++;
	while (src[srci] != '\0' && dsti + srci + 1 < size)
	{
		dst[dsti + srci + 1] = '\0';
		dst[dsti + srci] = src[srci];
		srci++;
	}
	return (dsti + ft_strlen(src));
}
