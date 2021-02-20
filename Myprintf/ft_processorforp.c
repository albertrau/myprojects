#include "libftprintf.h"

void	ft_writecharp(char c, t_forparser *d)
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

void	ft_readcountnumbp(unsigned long n, t_forparser *d)
{
	unsigned long res;

	res = n;
	if (res == 0)
	{
		g_flag3 = 3;
		g_countthexx++;
	}
	if (g_flag3 == 3 && d->accurasy == 0 && g_flag == 1)
	{
		g_countthexx--;
		return ;
	}
	if (res / 16 != 0 && res != 0)
		ft_readcountnumbp(res / 16, d);
	if (g_flag3 != 3)
		g_countthexx++;
}

void	ft_part4pu(int *null, unsigned long *m, t_forparser *d)
{
	while (d->flagminus == 1 && *null > 0)
	{
		write(1, "0", 1);
		*null -= 1;
		g_count++;
	}
	if (g_flag3 != 3 || d->accurasy != 0 || g_flag != 1 || g_flag2 == 2)
	{
		write(1, "0", 1);
		write(1, "x", 1);
		ft_writenumbp(*m, d);
	}
}

void	ft_writenumbp(unsigned long n, t_forparser *d)
{
	unsigned long res;

	res = n;
	if (res / 16 != 0)
		ft_writenumbp(res / 16, d);
	if ((res % 16 >= 0 && res % 16 <= 9) || res % 16 >= 16)
		ft_writechar(res % 16 + '0');
	else if (res % 16 == 10)
		ft_writecharp('a', d);
	else if (res % 16 == 11)
		ft_writecharp('b', d);
	else if (res % 16 == 12)
		ft_writecharp('c', d);
	else if (res % 16 == 13)
		ft_writecharp('d', d);
	else if (res % 16 == 14)
		ft_writecharp('e', d);
	else if (res % 16 == 15)
		ft_writecharp('f', d);
}

int		ft_processorp(t_forparser *d, int width, int null)
{
	unsigned long m;

	m = va_arg(g_rau, unsigned long);
	if (m == 0 && d->width == 0 && g_flag == 1)
	{
		forp1();
		return (g_count);
	}
	if (m == 0 && d->width > 0 && g_flag == 1)
	{
		forp(d);
		return (g_count);
	}
	ft_readcountnumbp(m, d);
	forp2(&width, &null, d);
	if (d->flagminus == 0)
	{
		ft_part1u(d, &width);
		ft_part2u(&width, &null);
		ft_part3u(&width, &null, &g_countthexx, d);
	}
	ft_part4pu(&null, &m, d);
	ft_part5u(&width, &null, d);
	ft_part6u(&width, &null, d);
	return (g_count += 2);
}
