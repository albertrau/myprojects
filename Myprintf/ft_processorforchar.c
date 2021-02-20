#include "libftprintf.h"

void	ft_part2c(int *width, t_forparser *d)
{
	if (d->flagminus == 1)
	{
		while (*width > 0)
		{
			write(1, " ", 1);
			*width -= 1;
			g_count++;
		}
	}
}

int		ft_processorchar(t_forparser *d)
{
	int		len;
	int		width;
	char	str;

	str = (char)va_arg(g_rau, int);
	len = 1;
	width = d->width - len;
	if (d->flagminus == 0)
	{
		while (width > 0)
		{
			write(1, " ", 1);
			width--;
			g_count++;
		}
	}
	write(1, &str, 1);
	g_count++;
	ft_part2c(&width, d);
	return (g_count);
}

void	ft_processorprocent1(int *width)
{
	while (*width > 0)
	{
		write(1, "0", 1);
		*width -= 1;
		g_count++;
		g_flag5 = 5;
	}
}

void	ft_processorprocent2(int *width)
{
	while (*width > 0)
	{
		write(1, " ", 1);
		*width -= 1;
		g_count++;
	}
}

int		ft_processorprocent(t_forparser *d, int len)
{
	int		width;
	char	str;

	str = '%';
	width = d->width - len;
	if (d->flagnull == 1 && d->flagminus != 1)
		ft_processorprocent1(&width);
	if (d->flagminus == 0 && g_flag5 != 5)
		ft_processorprocent2(&width);
	write(1, &str, 1);
	if (d->flagminus == 1)
	{
		while (width > 0)
		{
			write(1, " ", 1);
			width--;
			g_count++;
		}
	}
	g_count++;
	ft_part2c(&width, d);
	return (g_count);
}
