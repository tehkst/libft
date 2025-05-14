#include "libft.h"

static t_list	*free_and_clear(t_list *lst, void *content, void (*del)(void *))
{
	if (del)
		del(content);
	ft_lstclear(&lst, del);
	return (NULL);
}

t_list *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list *new_list;
	t_list *new_node;
	void   *new_content;

	if (!lst || !f)
		return NULL;
	new_list = NULL;
	while (lst)
	{
		new_content = f(lst->content);
		new_node = ft_lstnew(new_content);
		if (!new_node)
			return (free_and_clear(new_list, new_content, del));
		ft_lstadd_back(&new_list, new_node);
		lst = lst->next;
	}
	return (new_list);
}
