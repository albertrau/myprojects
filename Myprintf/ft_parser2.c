#include "libftprintf.h"

void	ft_parser2(const char *format)
{
	if (format[g_i] != '\0')
	{
		write(1, &format[g_i], 1);
		g_i++;
		g_count++;
	}
}

void	ft_parser3(const char *format)
{
	while (format[g_i] == '%' && format[g_i + 1] == '%')
	{
		write(1, &format[g_i], 1);
		g_i += 2;
		g_count++;
	}
}

void	ft_parser4(const char *format, t_forparser *fp)
{
	if (format[g_i] == '0' || format[g_i] == '-')
		g_i += ft_flag(&format[g_i], fp);
	if ((format[g_i] >= '1' && format[g_i] <= '9') || format[g_i] == '*')
		g_i += ft_width(&format[g_i], fp);
	if (format[g_i] == '.')
		g_i += ft_accurasy(&format[g_i], fp, 0, 0);
	g_i += ft_type(format[g_i], fp);
}
