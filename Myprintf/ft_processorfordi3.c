#include "libftprintf.h"

void	ft_processor_di3(t_forparser *d, int *null, int *width, int *len)
{
	if (*null > 0 || *len == 0 || (d->accurasy == 1 && *len == 1) \
	|| (d->accurasy == *len))
	{
		if (g_flag2 == 2)
			*width = d->width - *len - *null - 1;
		else
			*width = d->width - *len - *null;
		if (*width > 0 && g_flag6 == 6)
		{
			*width -= 1;
			*null += 1;
		}
		if (g_flag6 == 6 && d->width > d->accurasy && d->accurasy > *len)
		{
			*width += 1;
			*null -= 1;
		}
	}
	else if (*null < 0)
		*width = d->width - *len;
}

void	ft_processor_di4(int *m)
{
	if (*m < 0)
	{
		*m = *m * -1;
		g_count++;
		g_flag6 = 6;
	}
}

void	ft_part_3_2u(t_forparser *d, int **width, int **len)
{
	while (**width > 0 && **len == 0 && g_flag3 == 3)
	{
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
