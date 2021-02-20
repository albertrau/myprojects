#include "libftprintf.h"

void	ft_writenumb_fordi(int n)
{
	unsigned int res;

	res = n;
	if (res / 10 != 0)
		ft_writenumb_fordi(res / 10);
	ft_writechar(res % 10 + '0');
}

int		ft_countsymbols_di(int m, t_forparser *d)
{
	int count;
	int r;

	count = 0;
	while (m != 0)
	{
		m = m / 10;
		count++;
	}
	if (count == 0)
	{
		count++;
		g_flag3 = 3;
	}
	r = count;
	if (g_flag3 == 3 && d->accurasy == 0 && g_flag == 1)
	{
		r--;
		g_flag21 = 21;
		return (r);
	}
	return (count);
}

void	ft_part1_di(t_forparser *d, int *width)
{
	while (*width > 0 && d->accurasy == 0 && (g_flag == 0 || g_flag2 == 2))
	{
		ft_part1_2_di(d, &width);
		if (d->flagnull == 0)
		{
			if (g_flag6 == 6 && g_flag8 != 8 && *width < 0)
			{
				write(1, "-", 1);
				g_flag8 = 8;
			}
			write(1, " ", 1);
			*width -= 1;
			g_count++;
		}
	}
}

void	ft_part2_di(int *width, int *null)
{
	while (*width > 0 && *null > 0)
	{
		while (*width > 0)
		{
			g_flag18 = 18;
			*width -= 1;
			write(1, " ", 1);
			g_count++;
		}
		if (*width == 0 && g_flag6 == 6 && g_flag9 != 9 && g_flag18 == 18)
		{
			write(1, "-", 1);
			g_flag9 = 9;
		}
		while (*null > 0)
		{
			*null -= 1;
			write(1, "0", 1);
			g_count++;
			g_flag19 = 19;
		}
	}
}
