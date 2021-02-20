#include "libftprintf.h"

void	ft_part5u(int *width, int *null, t_forparser *d)
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

void	ft_part6u(int *width, int *null, t_forparser *d)
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
