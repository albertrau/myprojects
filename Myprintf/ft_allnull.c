#include "libftprintf.h"

void	allnull(t_forparser *fp)
{
	fp->flagnull = 0;
	fp->flagminus = 0;
	fp->width = 0;
	fp->accurasy = 0;
	fp->type = 0;
	fp->afterpercent = 0;
	fp->howmanysymbols = 0;
	fp->widthminussymbols = 0;
	fp->accurminussymbols = 0;
	allnull2();
}

void	allnull2(void)
{
	g_flag = 0;
	g_flag2 = 0;
	g_flag3 = 0;
	g_flag5 = 0;
	g_flag6 = 0;
	g_flag7 = 0;
	g_flag8 = 0;
	g_flag9 = 0;
	g_flag10 = 0;
	g_flag11 = 0;
	g_flag12 = 0;
	g_flag13 = 0;
	g_flag14 = 0;
	g_flag15 = 0;
	g_flag16 = 0;
	g_flag17 = 0;
	g_flag18 = 0;
	g_flag19 = 0;
	g_flag20 = 0;
	g_flag21 = 0;
	g_flag22 = 0;
	g_countthexx = 0;
}
