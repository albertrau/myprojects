
#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char *str;

	str = malloc(count * size);
	if (str == NULL)
		return (NULL);
	ft_memset(str, 0, count * size);
	return (str);
}
