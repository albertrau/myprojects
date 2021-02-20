#include "libftprintf.h"

int		ft_flag(const char *s, t_forparser *a)
{
	int n;

	n = 0;
	while (s[n] == '0' || s[n] == '-')
	{
		if (s[n] == '0')
			a->flagnull = 1;
		if (s[n] == '-')
			a->flagminus = 1;
		n++;
	}
	return (n);
}

int		ft_width(const char *s, t_forparser *b)
{
	int r;
	int w;

	w = 0;
	r = 0;
	if (s[r] == '*')
	{
		b->width = va_arg(g_rau, int);
		if (b->width < 0)
		{
			b->flagminus = 1;
			b->width = b->width * -1;
		}
		r++;
		return (r);
	}
	if (s[r] >= '1' && s[r] <= '9')
	{
		b->width = ft_atoi(&s[r]);
		w = ft_countsymbols(b->width, b);
	}
	return (w);
}

int		ft_accurasy(const char *s, t_forparser *c, int a, int q)
{
	c->accurasy = 0;
	while (s[q] == '.')
	{
		q++;
		while (s[q] == '0')
			q++;
		g_flag = 1;
	}
	if (s[q] == '*')
	{
		c->accurasy = va_arg(g_rau, int);
		if (c->accurasy < 0)
		{
			c->accurasy = 0;
			g_flag2 = 2;
		}
		q++;
		g_flag = 1;
		return (q);
	}
	ft_accurasy2(s, c, &a, &q);
	return (q);
}

int		ft_type(char s, t_forparser *d)
{
	if (ft_mystrchr("dpuicsxX%", s))
	{
		d->type = s;
		if (d->type == 's')
			ft_processorstr(d);
		else if (d->type == 'c')
			ft_processorchar(d);
		else if (d->type == 'u')
			ft_processoru(d, 0, 0, 0);
		else if (d->type == 'x' || d->type == 'X')
			ft_processorthexx(d, 0, 0);
		else if (d->type == 'p')
			ft_processorp(d, 0, 0);
		else if (d->type == 'd' || d->type == 'i')
			ft_processor_di(d, 0, 0);
		else if (d->type == '%')
			ft_processorprocent(d, 1);
	}
	d->type = 0;
	return (1);
}

void	ft_parser(t_forparser *fp, const char *format)
{
	int m;

	allnull(fp);
	if (format == 0)
		return ;
	while (format[g_i])
	{
		if (format[g_i] == '%')
		{
			ft_parser3(format);
			if (format[g_i] == '%')
			{
				m = g_i;
				m++;
				g_i++;
				ft_parser4(format, fp);
				fp->afterpercent = g_i - m;
				return ;
			}
		}
		ft_parser2(format);
	}
	allnull(fp);
}
