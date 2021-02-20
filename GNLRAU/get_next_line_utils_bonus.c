

#include "get_next_line_bonus.h"

size_t		ft_strlen(const char *s)
{
	size_t		len;

	len = 0;
	if (s == NULL)
		return (0);
	while (*s)
	{
		s++;
		len++;
	}
	return (len);
}

char		*ft_strdup(const char *a)
{
	char		*str;
	int			i;
	int			m;

	i = 0;
	m = 0;
	while (a[m])
		m++;
	if (!(str = malloc(sizeof(char) * (m + 1))))
		return (NULL);
	while (a[i])
	{
		str[i] = a[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char		*ft_strchr(const char *s, int n)
{
	char		*str;

	str = (char*)s;
	while (*str && *str != n)
		str++;
	if (*str == n)
		return (str);
	return (0);
}

char		*ft_strcpy(char *s1, const char *s2)
{
	size_t		i;

	i = 0;
	while (s2[i])
	{
		s1[i] = s2[i];
		i++;
	}
	s1[i] = '\0';
	return (s1);
}

char		*ft_clear(char *s)
{
	int			i;

	if (s)
	{
		i = -1;
		while (s[++i])
			s[i] = '\0';
		free(s);
	}
	return (0);
}
