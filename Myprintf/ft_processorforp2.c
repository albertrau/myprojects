#include "libftprintf.h"

void	forp1(void)
{
	write(1, "0", 1);
	write(1, "x", 1);
	g_count += 2;
}

void	forp(t_forparser *d)
{
	d->width -= 2;
	if (d->flagminus == 0)
	{
		while (d->width > 0)
		{
			write(1, " ", 1);
			d->width--;
			g_count++;
		}
		write(1, "0", 1);
		write(1, "x", 1);
	}
	if (d->flagminus == 1)
	{
		write(1, "0", 1);
		write(1, "x", 1);
		while (d->width > 0)
		{
			write(1, " ", 1);
			d->width--;
			g_count++;
		}
	}
	g_count += 2;
}

void	forp2(int *width, int *null, t_forparser *d)
{
	*null = d->accurasy - g_countthexx;
	if (*null > 0 || g_countthexx == 0)
		*width = d->width - g_countthexx - *null - 2;
	else if (*null < 0)
		*width = d->width - g_countthexx - 2;
}
