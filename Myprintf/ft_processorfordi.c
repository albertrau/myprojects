#include "libftprintf.h"

void	ft_part3_di(int *width, int *null, int *len, t_forparser *d)
{
	ft_part3_2_di(d, &width, &len);
	while (*width < 0 && *null > 0)
	{
		if (g_flag6 == 6 && g_flag12 != 12)
		{
			write(1, "-", 1);
			g_flag12 = 12;
			g_flag17 = 17;
		}
		*null -= 1;
		write(1, "0", 1);
		g_count++;
	}
	while (*width > 0 && *null < 0)
	{
		if (d->flagnull == 1 && g_flag21 == 21)
			write(1, "0", 1);
		else
			write(1, " ", 1);
		*width -= 1;
		g_count++;
	}
}

void	ft_part4_di(int *null, int *m, int *width, t_forparser *d)
{
	int g;
	int len;

	g = *m;
	len = 0;
	while (g != 0)
	{
		g = g / 10;
		len++;
	}
	if (g_flag6 == 6)
		len++;
	ft_part4_2di(d, &null, &width, &len);
	if (g_flag3 != 3 || d->accurasy != 0 || g_flag != 1 || g_flag2 == 2)
	{
		ft_part4_3di(d, &null, &len);
		ft_writenumb_fordi(*m);
	}
}

void	ft_part5_di(int *width, int *null, t_forparser *d)
{
	if (d->flagminus == 1)
	{
		while (*width > 0 && d->accurasy == 0 && g_flag == 0)
		{
			write(1, " ", 1);
			*width -= 1;
			g_count++;
		}
		while (*width > 0 && *null > 0)
		{
			while (*width > 0)
			{
				*width -= 1;
				write(1, " ", 1);
				g_count++;
			}
			while (*null > 0)
			{
				*null -= 1;
				write(1, "0", 1);
				g_count++;
			}
		}
	}
}

void	ft_part6_di(int *width, int *null, t_forparser *d)
{
	if (d->flagminus == 1)
	{
		while (*width < 0 && *null > 0)
		{
			*null -= 1;
			write(1, "0", 1);
			g_count++;
		}
		while (*width > 0 && (*null == 0 || *null < 0))
		{
			*width -= 1;
			write(1, " ", 1);
			g_count++;
		}
	}
}

int		ft_processor_di(t_forparser *d, int width, int null)
{
	int m;
	int len;

	m = va_arg(g_rau, int);
	ft_processor_di4(&m);
	if (g_flag6 == 6)
		len = ft_countsymbols_di(m, d) + 1;
	else
		len = ft_countsymbols_di(m, d);
	ft_processor_di2(d, &null, &len);
	ft_processor_di3(d, &null, &width, &len);
	if (d->flagminus == 0)
	{
		ft_part1_di(d, &width);
		ft_part2_di(&width, &null);
		ft_part3_di(&width, &null, &len, d);
	}
	ft_part4_di(&null, &m, &width, d);
	ft_part5_di(&width, &null, d);
	ft_part6_di(&width, &null, d);
	return (g_count);
}
