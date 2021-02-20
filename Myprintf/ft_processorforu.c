#include "libftprintf.h"

void	ft_writechar(char c)
{
	write(1, &c, 1);
	g_count++;
}

void	ft_writenumb(unsigned int n)
{
	unsigned int res;

	res = n;
	if (res / 10 != 0)
		ft_writenumb(res / 10);
	ft_writechar(res % 10 + '0');
}

int		ft_processoru(t_forparser *d, int width, int null, int len)
{
	unsigned int m;

	m = va_arg(g_rau, unsigned int);
	len = ft_countsymbols(m, d);
	null = d->accurasy - len;
	if (null > 0 || len == 0 || (d->accurasy == len))
	{
		if (g_flag2 == 2)
			width = d->width - len - null - 1;
		else
			width = d->width - len - null;
	}
	else if (null < 0)
		width = d->width - len;
	if (d->flagminus == 0)
	{
		ft_part1u(d, &width);
		ft_part2u(&width, &null);
		ft_part3u(&width, &null, &len, d);
	}
	ft_part4u(&null, &m, d);
	ft_part5u(&width, &null, d);
	ft_part6u(&width, &null, d);
	return (g_count);
}
