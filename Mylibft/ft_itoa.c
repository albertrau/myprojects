

#include "libft.h"

static char		*swap(char *str, int size, int n)
{
	int				tmp;
	int				j;
	int				k;

	k = size - 1;
	j = (n < 0) ? 1 : 0;
	while (j <= k)
	{
		tmp = str[k];
		str[k] = str[j];
		str[j] = tmp;
		j++;
		k--;
	}
	return (str);
}

static char		*setchar(int n, char *str, int size)
{
	int				i;
	unsigned int	num;

	i = (n < 0) ? 1 : 0;
	if (n < 0)
	{
		str[0] = '-';
		num = n * (-1);
	}
	else
		num = n;
	while (num != 0)
	{
		str[i] = num % 10 + '0';
		num = num / 10;
		i++;
	}
	str[i] = '\0';
	return (swap(str, size, n));
}

static int		ft_count(int n)
{
	int				size;

	size = 0;
	while (n != 0)
	{
		n = n / 10;
		size++;
	}
	return (size);
}

char			*ft_itoa(int n)
{
	int				size;
	char			*str;

	size = ft_count(n);
	if (n == 0)
		return (ft_strdup("0"));
	if (n < 0)
		size++;
	str = (char*)malloc(sizeof(char) * size + 1);
	if (str == NULL)
		return (NULL);
	str = setchar(n, str, size);
	return (str);
}
