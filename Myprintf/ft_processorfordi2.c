#include "libftprintf.h"

void	ft_part1_2_di(t_forparser *d, int **width)
{
	if (d->flagnull == 1)
	{
		if (g_flag6 == 6 && g_flag7 != 7)
		{
			write(1, "-", 1);
			g_flag7 = 7;
			g_flag16 = 16;
		}
		write(1, "0", 1);
		**width -= 1;
		g_count++;
	}
}

void	ft_part3_2_di(t_forparser *d, int **width, int **len)
{
	while (**width > 0 && **len == 0 && g_flag3 == 3)
	{
		if (g_flag6 == 6 && g_flag11 != 11)
		{
			write(1, "-", 1);
			g_flag11 = 11;
		}
		if ((d->flagnull == 1 && g_flag21 != 21))
			write(1, "0", 1);
		else
			write(1, " ", 1);
		**width -= 1;
		g_count++;
	}
	while (**width > 0 && d->width > d->accurasy)
	{
		**width -= 1;
		write(1, " ", 1);
		g_count++;
	}
}

void	ft_part4_2di(t_forparser *d, int **null, int **width, int *len)
{
	if (d->flagminus == 1 && **null > 0)
	{
		if (**width <= 0 && g_flag6 == 6 && g_flag22 != 22)
			**null += 1;
		if (d->accurasy < d->width && g_flag6 == 6)
			**null = d->accurasy - *len;
		if (d->accurasy < d->width && d->accurasy > *len && \
		g_flag6 == 6 && d->flagminus == 1)
			**null += 1;
		while (d->flagminus == 1 && **null > 0)
		{
			if (g_flag6 == 6 && g_flag14 != 14)
			{
				write(1, "-", 1);
				g_flag14 = 14;
			}
			write(1, "0", 1);
			**null -= 1;
			g_count++;
			g_flag20 = 20;
		}
	}
}

void	ft_part4_3di(t_forparser *d, int **null, int *len)
{
	if (g_flag6 == 6 && g_flag15 != 15 && g_flag16 != 16 && \
	g_flag17 != 17 && g_flag19 != 19 && g_flag20 != 20)
	{
		write(1, "-", 1);
		g_flag15 = 15;
	}
	if ((g_flag17 == 17 || \
	(d->accurasy == *len && g_flag6 == 6)) && g_flag22 != 22)
	{
		write(1, "0", 1);
		g_count++;
	}
	if (d->accurasy == d->width && d->accurasy > 0)
	{
		if (g_flag6 == 6 && *len != d->accurasy && d->accurasy != d->width)
			**null += 1;
		while (**null > 0)
		{
			write(1, "0", 1);
			**null -= 1;
			g_count++;
		}
	}
}

void	ft_processor_di2(t_forparser *d, int *null, int *len)
{
	if (g_flag6 == 6 && d->accurasy > *len)
	{
		*null = d->accurasy - *len + 1;
		g_flag22 = 22;
	}
	else
		*null = d->accurasy - *len;
}
