#include "libftprintf.h"

void	ft_writecharthexx(char c, t_forparser *d)
{
	if (d->type == 88)
	{
		c = c - 32;
		write(1, &c, 1);
		g_count++;
		return ;
	}
	write(1, &c, 1);
	g_count++;
}

void	ft_readcountnumbthexx(unsigned int n, t_forparser *d)
{
	unsigned int res;

	res = n;
	if (res == 0)
	{
		g_flag3 = 3;
		g_countthexx++;
	}
	if (g_flag3 == 3 && d->accurasy == 0 && g_flag == 1)
	{
		g_countthexx--;
		g_flag21 = 21;
		return ;
	}
	if (res / 16 != 0 && res != 0)
		ft_readcountnumbthexx(res / 16, d);
	if (g_flag3 != 3)
		g_countthexx++;
}

void	ft_part4thexxu(int *null, unsigned int *m, t_forparser *d)
{
	while (d->flagminus == 1 && *null > 0)
	{
		write(1, "0", 1);
		*null -= 1;
		g_count++;
	}
	if (g_flag3 != 3 || d->accurasy != 0 || g_flag != 1 || g_flag2 == 2)
	{
		if (d->accurasy == d->width && d->accurasy > 0)
		{
			while (*null > 0)
			{
				write(1, "0", 1);
				*null -= 1;
				g_count++;
			}
		}
		ft_writenumbthexx(*m, d);
	}
}

void	ft_writenumbthexx(unsigned int n, t_forparser *d)
{
	unsigned int res;

	res = n;
	if (res / 16 != 0)
		ft_writenumbthexx(res / 16, d);
	if ((res % 16 >= 0 && res % 16 <= 9) || res % 16 >= 16)
		ft_writechar(res % 16 + '0');
	else if (res % 16 == 10)
		ft_writecharthexx('a', d);
	else if (res % 16 == 11)
		ft_writecharthexx('b', d);
	else if (res % 16 == 12)
		ft_writecharthexx('c', d);
	else if (res % 16 == 13)
		ft_writecharthexx('d', d);
	else if (res % 16 == 14)
		ft_writecharthexx('e', d);
	else if (res % 16 == 15)
		ft_writecharthexx('f', d);
}

int		ft_processorthexx(t_forparser *d, int width, int null)
{
	unsigned int m;

	m = va_arg(g_rau, unsigned int);
	ft_readcountnumbthexx(m, d);
	null = d->accurasy - g_countthexx;
	if (null > 0 || g_countthexx == 0 || \
	(d->accurasy == 1 && g_countthexx == 1) || (d->accurasy == g_countthexx))
	{
		if (g_flag2 == 2)
			width = d->width - g_countthexx - null - 1;
		else
			width = d->width - g_countthexx - null;
	}
	else if (null < 0)
		width = d->width - g_countthexx;
	if (d->flagminus == 0)
	{
		ft_part1u(d, &width);
		ft_part2u(&width, &null);
		ft_part3u(&width, &null, &g_countthexx, d);
	}
	ft_part4thexxu(&null, &m, d);
	ft_part5u(&width, &null, d);
	ft_part6u(&width, &null, d);
	return (g_count);
}
