

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int res;

	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n = n * -1;
	}
	res = n;
	if (res / 10 != 0)
		ft_putnbr_fd(res / 10, fd);
	ft_putchar_fd(res % 10 + '0', fd);
}
