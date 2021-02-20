#include "libftprintf.h"

void	ft_part1u(t_forparser *d, int *width)
{
	while (*width > 0 && d->accurasy == 0 && (g_flag == 0 || g_flag2 == 2))
	{
		if (d->flagnull == 1)
		{
			write(1, "0", 1);
			*width -= 1;
			g_count++;
		}
		if (d->flagnull == 0)
		{
			write(1, " ", 1);
			*width -= 1;
			g_count++;
		}
	}
}

void	ft_part2u(int *width, int *null)
{
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

void	ft_part3u(int *width, int *null, int *len, t_forparser *d)
{
	ft_part_3_2u(d, &width, &len);
	while (*width < 0 && *null > 0)
	{
		*null -= 1;
		write(1, "0", 1);
		g_count++;
	}
	while (*width > 0 && *null < 0)
	{
		if ((d->flagnull == 1 && g_flag21 != 21))
			write(1, "0", 1);
		else
			write(1, " ", 1);
		*width -= 1;
		g_count++;
	}
}

void	ft_part4u(int *null, unsigned int *m, t_forparser *d)
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
		ft_writenumb(*m);
	}
}
