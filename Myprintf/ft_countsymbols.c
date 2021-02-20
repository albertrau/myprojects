#include "libftprintf.h"

int		ft_countsymbols(unsigned int m, t_forparser *d)
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
