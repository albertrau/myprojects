

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	unsigned int	y;
	char			*str;

	i = 0;
	y = 0;
	if (s == NULL)
		return (NULL);
	if (start >= ft_strlen(s))
	{
		if (!(str = (char*)malloc(sizeof(char) * 1)))
			return (NULL);
		str[0] = '\0';
		return (str);
	}
	while (y != start)
		y++;
	if (!(str = (char*)malloc(sizeof(char) * len + 1)))
		return (NULL);
	while (s[y] && len--)
	{
		str[i++] = s[y++];
	}
	str[i] = '\0';
	return (str);
}
