

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list *a;
	t_list *b;

	if (!lst)
		return (NULL);
	if (!(b = ft_lstnew(f(lst->content))))
		return (NULL);
	lst = lst->next;
	while (lst)
	{
		if (!(a = ft_lstnew(f(lst->content))))
		{
			ft_lstclear(&b, del);
			return (NULL);
		}
		lst = lst->next;
		ft_lstadd_back(&b, a);
	}
	return (b);
}
