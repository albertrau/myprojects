#include "libftprintf.h"

int		ft_mystrlen(const char *s)
{
	int		i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

int		ft_strwithoutminus(int *width, t_forparser *d)
{
	if (d->flagminus == 0)
		while (*width > 0)
		{
			write(1, " ", 1);
			*width -= 1;
			g_count++;
		}
	return (g_count);
}

int		ft_strwritesymbols(int *prec, char *str, int *i)
{
	while (*prec != 0)
	{
		write(1, &str[*i], 1);
		*i += 1;
		*prec -= 1;
		g_count++;
	}
	return (g_count);
}

int		ft_strwithminus(int *width, t_forparser *d)
{
	if (d->flagminus == 1)
		while (*width > 0)
		{
			write(1, " ", 1);
			*width -= 1;
			g_count++;
		}
	return (g_count);
}

int		ft_processorstr(t_forparser *d)
{
	char	*str;
	int		i;
	int		prec;
	int		width;
	int		len;

	i = 0;
	str = va_arg(g_rau, char*);
	if (str == 0)
		str = "(null)";
	len = ft_mystrlen(str);
	prec = ((g_flag == 1 && g_flag2 != 2 && d->accurasy < len) ? \
	d->accurasy : len);
	width = d->width - prec;
	ft_strwithoutminus(&width, d);
	ft_strwritesymbols(&prec, str, &i);
	ft_strwithminus(&width, d);
	g_flag = 0;
	return (g_count);
}
