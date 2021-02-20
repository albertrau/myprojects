

#include "libft.h"

int		ft_atoi(const char *str)
{
	int					k;
	unsigned long int	res;

	k = 1;
	res = 0;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			k = -1;
		str++;
	}
	while (ft_isdigit(*str) == 1)
	{
		res = res * 10 + (*str - 48);
		str++;
	}
	if (res - 1 > 9223372036854775807 && k == -1)
		return (0);
	if (res > 9223372036854775807 && k == 1)
		return (-1);
	return (k * res);
}
