/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jurenaul <jurenaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 21:03:22 by jurenaul          #+#    #+#             */
/*   Updated: 2022/11/12 15:53:21 by jurenaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*retrieve_line(int fd, char *buffer, char *backup)
{
	ssize_t		nbytes;
	char		*temp;

	nbytes = 1;
	while (nbytes > 0)
	{
		nbytes = read(fd, buffer, BUFFER_SIZE);
		if (nbytes == -1)
		{
			free(backup);
			return (0);
		}
		else if (nbytes == 0)
			break ;
		buffer[nbytes] = '\0';
		if (!backup)
			backup = ft_strdup("");
		temp = backup;
		backup = ft_strjoin(temp, buffer);
		free(temp);
		temp = NULL;
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (backup);
}

char	*extract(char *line)
{
	size_t	count;
	char	*backup;

	count = 0;
	while (line[count] != '\n' && line[count] != '\0')
		count++;
	if (line[count] == '\0' || line[1] == '\0')
		return (0);
	backup = ft_substr(line, count + 1, ft_strlen(line) - count);
	if (*backup == '\0')
	{
		free(backup);
		backup = NULL;
	}
	line[count + 1] = '\0';
	return (backup);
}

char	*get_next_line(int fd)
{
	char			*line;
	char			*buffer;
	static char		*backup;

	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		free(backup);
		free(buffer);
		backup = NULL;
		buffer = NULL;
		return (0);
	}
	if (!buffer)
		return (0);
	line = retrieve_line(fd, buffer, backup);
	free(buffer);
	buffer = NULL;
	if (!line)
		return (NULL);
	backup = extract(line);
	return (line);
}
