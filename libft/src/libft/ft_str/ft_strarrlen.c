
#include "libft.h"

size_t	ft_strarrlen(char **arr)
{
	size_t	i;

	i = 0;
	while (arr[i] != NULL)
		i++;
	return (i);
}
