#include "libftprintf.h"

char	ft_mystrchr(const char *str, char s)
{
	int i;

	i = 0;
	while (str[i] && str[i] != s)
		i++;
	if (str[i] == s)
		return (str[i]);
	return ('0');
}
