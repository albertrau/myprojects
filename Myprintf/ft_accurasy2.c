#include "libftprintf.h"

void	ft_accurasy2(const char *s, t_forparser *c, int *a, int *q)
{
	if (s[*q] >= '1' && s[*q] <= '9')
	{
		if (c->accurasy < 0)
		{
			c->accurasy = 0;
			g_flag2 = 2;
		}
		c->accurasy = ft_atoi(&s[*q]);
		*a = ft_countsymbols(c->accurasy, c);
		*q += *a;
	}
}
