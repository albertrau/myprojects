
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str1;
	int		i;
	int		a;

	i = 0;
	a = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	str1 = (char*)malloc(sizeof(char) * (ft_strlen(s1) + (ft_strlen(s2))) + 1);
	if (str1 == NULL)
		return (NULL);
	while (s1[a] != '\0')
	{
		str1[i] = s1[a];
		i++;
		a++;
	}
	a = 0;
	while (s2[a] != '\0')
	{
		str1[i++] = s2[a++];
	}
	str1[i] = '\0';
	return (str1);
}
