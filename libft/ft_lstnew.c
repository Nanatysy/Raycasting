#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new;
	int		i;

	new = (t_list*)malloc(sizeof(t_list) * 1);
	if (new)
	{
		i = ft_strlen(content);
		if (!(new->content = (char *)malloc(sizeof(char) * (i + 1))))
		{
			free(new);
			return (NULL);
		}
		ft_strlcpy(new->content, content, i + 1);
		new->next = NULL;
		return (new);
	}
	return (NULL);
}
