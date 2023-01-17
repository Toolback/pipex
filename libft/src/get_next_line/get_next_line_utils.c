// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   get_next_line_utils.c                              :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: jurenaul <jurenaul@student.42.fr>          +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2022/10/31 21:06:44 by jurenaul          #+#    #+#             */
// /*   Updated: 2022/11/12 15:53:17 by jurenaul         ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

// #include "libft.h"

// int	ft_strlen(const char *str)
// {
// 	int	i;

// 	i = 0;
// 	while (str[i])
// 		i++;
// 	return (i);
// }

// char	*ft_strjoin(const char *dest, const char *src)
// {
// 	int		i;
// 	int		j;
// 	char	*new;

// 	i = 0;
// 	j = 0;
// 	new = (char *)malloc(sizeof(char) * (ft_strlen(dest) + ft_strlen(src) + 1));
// 	if (!new)
// 		return (NULL);
// 	while (dest[i])
// 	{
// 		new[i] = dest[i];
// 		i++;
// 	}
// 	while (src[j])
// 	{
// 		new[i + j] = src[j];
// 		j++;
// 	}
// 	new[i + j] = '\0';
// 	return (new);
// }

// char	*ft_strchr(const char *s, int i)
// {
// 	while (*s)
// 	{
// 		if (*s == i)
// 			return ((char *)s);
// 		s++;
// 	}
// 	if (i == '\0')
// 		return ((char *)s);
// 	return (0);
// }

// char	*ft_strdup(const char *s)
// {
// 	int		i;
// 	int		j;
// 	char	*str;

// 	i = 0;
// 	j = ft_strlen(s);
// 	str = (char *)malloc(sizeof(*str) * (j + 1));
// 	while (i < j)
// 	{
// 		str[i] = s[i];
// 		i++;
// 	}
// 	str[i] = '\0';
// 	return (str);
// }

// char	*ft_substr(char const *s, unsigned int start, size_t len)
// {
// 	size_t	i;
// 	size_t	j;
// 	char	*str;

// 	str = (char *)malloc(sizeof(*s) * (len + 1));
// 	if (str == 0)
// 		return (NULL);
// 	i = 0;
// 	j = 0;
// 	while (s[i])
// 	{
// 		if (i >= start && j < len)
// 		{
// 			str[j] = s[i];
// 			j++;
// 		}
// 		i++;
// 	}
// 	str[j] = 0;
// 	return (str);
// }
