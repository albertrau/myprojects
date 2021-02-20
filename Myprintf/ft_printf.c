#include "libftprintf.h"

int		ft_printf(const char *str, ...)
{
	t_forparser a;

	g_i = 0;
	g_count = 0;
	g_countthexx = 0;
	allnull(&a);
	va_start(g_rau, str);
	ft_parser(&a, str);
	while (a.afterpercent != 0)
		ft_parser(&a, str);
	va_end(g_rau);
	return (g_count);
}
