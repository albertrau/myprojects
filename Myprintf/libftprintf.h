#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include "libft/libft.h"

typedef struct	s_forparser1
{
	int			width;
	int			accurasy;
	int			flagnull;
	int			flagminus;
	int			type;
	int			afterpercent;
	int			howmanysymbols;
	int			widthminussymbols;
	int			accurminussymbols;
}				t_forparser;

va_list			g_rau;
int				g_countthexx;
int				g_i;
int				g_count;
int				g_flag;
int				g_flag2;
int				g_flag3;
int				g_flag5;
int				g_flag6;
int				g_flag7;
int				g_flag8;
int				g_flag9;
int				g_flag10;
int				g_flag11;
int				g_flag12;
int				g_flag13;
int				g_flag14;
int				g_flag15;
int				g_flag16;
int				g_flag17;
int				g_flag18;
int				g_flag19;
int				g_flag20;
int				g_flag21;
int				g_flag22;

int				ft_printf(const char *str, ...);
int				ft_flag(const char *s, t_forparser *a);
int				ft_width(const char *s, t_forparser *b);
int				ft_accurasy(const char *s, t_forparser *c, int a, int q);
void			ft_accurasy2(const char *s, t_forparser *c, int *a, int *q);
int				ft_type(char s, t_forparser *d);
void			ft_parser(t_forparser *fp, const char *format);
void			ft_parser2(const char *format);
void			ft_parser3(const char *format);
void			ft_parser4(const char *format, t_forparser *fp);
char			ft_mystrchr(const char *str, char s);
void			allnull(t_forparser *fp);
void			allnull2();
int				ft_processorstr(t_forparser *d);
int				ft_strwithoutminus(int *width, t_forparser *d);
int				ft_strwritesymbols(int *prec, char *str, int *i);
int				ft_strwithminus(int *width, t_forparser *d);
int				ft_processorchar(t_forparser *d);
void			ft_part2c(int *width, t_forparser *d);
int				ft_processoru(t_forparser *d, int width, int null, int len);
void			ft_part1u(t_forparser *d, int *width);
void			ft_part2u(int *width, int *null);
void			ft_part3u(int *width, int *null, int *len, t_forparser *d);
void			ft_part_3_2u(t_forparser *d, int **width, int **len);
void			ft_part4u(int *null, unsigned int *m, t_forparser *d);
void			ft_part5u(int *width, int *null, t_forparser *d);
void			ft_part6u(int *width, int *null, t_forparser *d);
int				ft_countsymbols(unsigned int m, t_forparser *d);
void			ft_writenumb(unsigned int n);
void			ft_putchar(char c);
void			ft_writechar(char c);
int				ft_processorthexx(t_forparser *d, int width, int null);
void			ft_writenumbthexx(unsigned int n, t_forparser *d);
void			ft_readcountnumbthexx(unsigned int n, t_forparser *d);
void			ft_part4thexxu(int *null, unsigned int *m, t_forparser *d);
void			ft_writecharthexx(char c, t_forparser *d);
int				ft_mystrlen(const char *s);
int				ft_processorprocent(t_forparser *d, int len);
void			ft_processorprocent1(int *width);
void			ft_processorprocent2(int *width);
int				ft_processorp(t_forparser *d, int width, int null);
void			ft_writenumbp(unsigned long n, t_forparser *d);
void			ft_part4pu(int *null, unsigned long *m, t_forparser *d);
void			ft_writecharp(char c, t_forparser *d);
void			ft_readcountnumbp(unsigned long n, t_forparser *d);
void			forp(t_forparser *d);
void			forp1();
void			forp2(int *width, int *null, t_forparser *d);
int				ft_processor_di(t_forparser *d, int width, int null);
void			ft_processor_di2(t_forparser *d, int *null, int *len);
void			ft_processor_di3(t_forparser *d, int *null,
int *width, int *len);
void			ft_processor_di4(int *m);
void			ft_writenumb_fordi(int n);
void			ft_part1_di(t_forparser *d, int *width);
void			ft_part1_2_di(t_forparser *d, int **width);
void			ft_part2_di(int *width, int *null);
void			ft_part3_di(int *width, int *null, int *len, t_forparser *d);
void			ft_part3_2_di(t_forparser *d, int **width, int **len);
void			ft_part4_3di(t_forparser *d, int **null, int *len);
void			ft_part4_di(int *null, int *m, int *width, t_forparser *d);
void			ft_part4_2di(t_forparser *d, int **null, int **width, int *len);
void			ft_part5_di(int *width, int *null, t_forparser *d);
void			ft_part6_di(int *width, int *null, t_forparser *d);
int				ft_countsymbols_di(int m, t_forparser *d);

#endif
