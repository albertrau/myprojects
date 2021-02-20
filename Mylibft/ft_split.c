

#include "libft.h"

static char		**ft_freememory(char **array)
{
	int i;

	i = 0;
	while (array && array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
	return (NULL);
}

static char		**ft_memory(char const *s, char **array, char c, int countmain)
{
	int			i;
	int			flag1;
	int			r;
	int			m;

	flag1 = 0;
	i = -1;
	m = 0;
	while (s[++i] && countmain > m)
	{
		if (s[i] != c && flag1 == 0 && s[i] != '\0')
		{
			r = i;
			flag1 = 1;
		}
		if ((s[i + 1] == c || s[i + 1] == 0) && flag1 == 1)
		{
			flag1 = 0;
			if (!(array[m] = ft_substr(s, r, i - r + 1)))
				return (ft_freememory(array));
			m++;
		}
	}
	array[m] = NULL;
	return (array);
}

static int		ft_count(char const *s, char c)
{
	int			flag;
	int			count;

	count = 0;
	flag = 0;
	while (*s)
	{
		if (*s != c && flag == 0 && *s != '\0')
		{
			count++;
			flag = 1;
		}
		if (*s == c && flag == 1 && *s != '\0')
			flag = 0;
		s++;
	}
	return (count);
}

char			**ft_split(char const *s, char c)
{
	int			countmain;
	char		**arraylast;
	char		**array;

	if (s == NULL)
		return (NULL);
	countmain = ft_count(s, c);
	array = (char**)malloc(sizeof(array) * (countmain + 1));
	if (array == NULL)
		return (NULL);
	arraylast = ft_memory(s, array, c, countmain);
	return (arraylast);
}
