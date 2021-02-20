

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list *p;

	p = *lst;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	if (!new)
		return ;
	while (p->next != NULL)
		p = p->next;
	p->next = new;
}
