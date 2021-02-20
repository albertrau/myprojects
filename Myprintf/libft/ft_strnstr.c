

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t i;
	size_t size;

	i = 0;
	if (*needle == 0)
		return ((char*)haystack);
	size = ft_strlen(needle);
	while (i < len && haystack[i] != '\0')
	{
		if ((i + size) <= len)
			if (haystack[i] == needle[0] &&\
			!ft_strncmp(&haystack[i], needle, size))
				return ((char*)&haystack[i]);
		i++;
	}
	return (NULL);
}
